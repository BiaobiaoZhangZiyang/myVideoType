#include "tools.hpp"

int main(){
    char windowName[] = "Test";
    cv::Mat canvas(Height, Width, CV_8UC3, White);
    cv::Mat logo_orignal = cv::imread("/home/zzy/Desktop/myVideoType/pics/zju_logo.png", 1);
    cv::Mat logo(logo_orignal.rows, logo_orignal.cols,CV_8UC3);
    std::string text = "Computer Vision Project 0";
    int fontType = cv::FONT_HERSHEY_COMPLEX;
    double fontScale = 2.0;
    int textThickness = 3;

    cv::Size textSize = cv::getTextSize(text, fontType, fontScale, textThickness, 0);
    //center the text
    cv::Point textOrg((logo_orignal.cols - textSize.width)/2,(logo_orignal.rows + textSize.height)/2);

    for(double i = 0; i<256.0; i+=0.1){
        cv::Mat mask = tools::colorized(logo_orignal.rows, logo_orignal.cols, 255.0, i, 0.0);
        cv::Mat theCanvas(Height, Width, CV_8UC3, White);
        cv::bitwise_and(logo_orignal, mask, logo);
        tools::insertIntoRegion(theCanvas, logo, 0, 0, 0.5); 
        if(i > 128.0){
            cv::Mat textCanvas(logo_orignal.rows, logo_orignal.cols, CV_8UC3, cv::Scalar(0.0, 0.0, 0.0));
            cv::putText(textCanvas, text , textOrg, fontType, fontScale, cv::Scalar::all(i), textThickness);
            int y = logo.rows * 0.5;
            tools::insertIntoRegion(theCanvas, textCanvas, 0, y, 0.3); 
        }
        tools::showCurrentPics(windowName, theCanvas);
    }

    // 保存上面每一帧的图片
    // 对上面最后一帧图片操作，形成过场动画（https://blog.csdn.net/zhenguo26/article/details/82805445），同时形成下一个场景的canvas
    // 对保存的照片形成视频
    // 捕获空格操作
    
    return 0;
}
