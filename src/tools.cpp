#include "tools.hpp"

cv::Mat freezeScreen(cv::Mat image){
    cv::Mat screenShot;
    cv::GaussianBlur(image, screenShot, cv::Size(0, 0), 5, 5); // what does these params means???
    cv::circle(screenShot, cv::Point(screenShot.cols/2, screenShot.rows/2), 50, White, 3);
    cv::rectangle(screenShot, cv::Point(screenShot.cols/2-20, screenShot.rows/2-30), cv::Point(screenShot.cols/2-10, screenShot.rows/2+30), White, -1, cv::LINE_8, 0);
    cv::rectangle(screenShot, cv::Point(screenShot.cols/2+20, screenShot.rows/2-30), cv::Point(screenShot.cols/2+10, screenShot.rows/2+30), White, -1, cv::LINE_8, 0);
    return screenShot;
}
void tools::showCurrentPics(char* windowName, cv::Mat image, int seconds){
    int keyInput;
    cv::imshow(windowName, image); // 1. fundmantal images show line 4-5
    keyInput = cv::waitKey( seconds );
    if(keyInput == 32){ // 32 is the Space button's ASCII value
        cv::imshow(windowName, freezeScreen(image));// show a freeze screen image
        cv::waitKey(0);
    }
}

void tools::insertIntoRegion(cv::Mat& canvas, cv::Mat picture, int _x, int _y, double scale){
    cv::Mat resizedPicture = picture;
    cv::resize(picture, resizedPicture, cv::Size(), scale, scale); // 2.resize picture by scale line 10
    int y = _y + canvas.rows/2 - resizedPicture.rows/2; // 3.ROI region of interest line 11-14
    int x = _x + canvas.cols/2 - resizedPicture.cols/2;
    resizedPicture.copyTo(canvas(cv::Rect(x, y, resizedPicture.cols, resizedPicture.rows)));
}

cv::Mat tools::colorized(int rows, int cols, double B, double G, double R){
    return cv::Mat(rows, cols, CV_8UC3, cv::Scalar(B, G, R));
}


void tools::save(cv::Mat image, std::string path, int& timeStep){
    try{
        cv::imwrite(path+std::to_string(timeStep)+".jpg", image);
        timeStep++;
    }
    catch(const cv::Exception& ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
}

void tools::sceneTransistion(int rows, int cols, char* windowName, cv::Mat image, std::string path, int& timeStep){
    cv::Mat imageCopy(rows, cols, CV_8UC3);
    for(int radius = rows/2; radius>0; radius-=5){
        cv::Mat result;
        image.copyTo(imageCopy);
        cv::Mat mask(rows, cols, CV_8UC3, Black);
        cv::circle(mask, cv::Point(cols/2, rows/2), radius, White, -1);
        cv::bitwise_and(imageCopy, mask, result);
        tools::showCurrentPics(windowName, result);
        tools::save(result, path, timeStep);
    }
}

void tools::sceneTransistion2(cv::Mat& image, char* windowName, std::string outputPath , int& timeStep){
    for(int i = 0; i<Height-10; i++)
        for(int j = 0; j<Width-10; j++){
            if(i % 10 == 0 && j % 10 == 0){
                int blue = image.at<cv::Vec3b>(i, j)[0];
                int green = image.at<cv::Vec3b>(i, j)[1];
                int red = image.at<cv::Vec3b>(i, j)[2];
                for(int ii = 0 ;ii<10;ii++)
                    for(int jj = 0; jj<10; jj++){
                        image.at<cv::Vec3b>(i+ii, j+jj)[0] = blue;
                        image.at<cv::Vec3b>(i+ii, j+jj)[1] = green;
                        image.at<cv::Vec3b>(i+ii, j+jj)[2] = red;
                    }
                }
        tools::showCurrentPics(windowName, image);
        tools::save(image, outputPath, timeStep);
    }
}

void tools::produceVideo(std::string outputDir, int timeStep){
    cv::VideoWriter writer;
    int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G'); // https://www.fourcc.org/codecs.php
    double fps = 24.0; 
    std::string fileName = outputDir+"myVideo.avi";
    writer.open(fileName, codec, fps, cv::Size(Width, Height));
    if(!writer.isOpened()){
        std::cout<<"Could not produce video to ->"<<std::endl;
        return;
    }
    for(int i = 0; i < timeStep; i++){
        cv::Mat frame = cv::imread(outputDir+std::to_string(i)+".jpg", 1);
        writer.write(frame);
    }

}