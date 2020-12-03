#include "sceneOne.hpp"

cv::Mat scene1::sceneOne(std::string inputDir, std::string outputDir, char* windowName, int& timeStep){
    /* -------------------------- LOGO and PERSONAL Imfo----------------------------------*/
    cv::Mat logo_orignal = cv::imread(inputDir+"zju_logo.png", 1); // change the absolute dir
    cv::Mat personalImage = cv::imread(inputDir+"zzy.png", 1);
    cv::Mat firstSceneEnd(Height, Width, CV_8UC3);

    /* ---------------------------------- Text --------------------------------------------*/
    struct scene1::sceneText text;
    text.fontScale = 2.0;
    text.textThickness = 3;
    text.fontType = cv::FONT_HERSHEY_COMPLEX;
    text.value = "CV Course 1st Project";
    text.textSize = cv::getTextSize(text.value, text.fontType, text.fontScale, text.textThickness, 0);
    text.textOrg = cv::Point((logo_orignal.cols - text.textSize.width)/2,(logo_orignal.rows + text.textSize.height)/2);

    /* ---------------------------------- ShowTime --------------------------------------------*/
    // Logo color from White to Green-Blue
    int center_x_bias = 0;
    int center_y_bias = 0;
    int center_belowLogo_x_bias = 0;
    int center_belowlogo_y_bias = logo_orignal.rows * LogoScale;
    for(double i = 255.0;i>0.0;i-=1.0){
        if(i < 128){
            subScene(logo_orignal, personalImage, cv::Scalar(255.0, 255.0, i), text, center_belowLogo_x_bias, center_belowlogo_y_bias, true, outputDir, windowName, timeStep);
        }
        else{
            subScene(logo_orignal, personalImage, cv::Scalar(255.0, 255.0, i), text, center_x_bias, center_y_bias, false, outputDir, windowName, timeStep);
        }
    }
    // logo color from Green-Blue to Blue, and shift to the left-center
    int moving_x = 0;
    for(double i = 255.0;i>80.0;i-=1.0){
        if(moving_x*-1 < logo_orignal.cols/2 - logo_orignal.cols/4){
            moving_x --;
        }
        subScene(logo_orignal, personalImage, cv::Scalar(255.0, i, 0.0), text, moving_x, center_belowlogo_y_bias, true, outputDir, windowName, timeStep);
    }
    // logo color from Blue to ZJU Blue and add personal image
    for(double i = 255.0;i>157.0;i-=1.0){
        moving_x--;
        subScene(logo_orignal, personalImage, cv::Scalar(i, 80.0, 0.0), text, moving_x, center_belowlogo_y_bias, true, outputDir, windowName, timeStep, true);
        if(i == 158){
            return subScene(logo_orignal, personalImage, cv::Scalar(i-1, 80.0, 0.0), text, moving_x, center_belowlogo_y_bias, true, outputDir, windowName, timeStep, true);
        }
    }
    return cv::Mat(Width, Height, CV_8UC3, White); //to get rid of the warning message
}

cv::Mat scene1::subScene(cv::Mat logo_orignal, cv::Mat personalImage, cv::Scalar color, struct scene1::sceneText text, int x, int y, bool textFlag, std::string outputDir, char* windowName,int& timeStep, bool personFlag){
    cv::Mat editedLogo(logo_orignal.rows, logo_orignal.cols, CV_8UC3, Black);
    cv::Mat colorMask(logo_orignal.rows, logo_orignal.cols, CV_8UC3, color);  
    cv::Mat canvas(Height, Width, CV_8UC3, Black);
    cv::bitwise_and(logo_orignal, colorMask, editedLogo); // 4. bitwise operation
    tools::insertIntoRegion(canvas, editedLogo, x, 0, LogoScale);
    // decide when to display txt
    if(textFlag){
        cv::Mat textCanvas(logo_orignal.rows, logo_orignal.cols, CV_8UC3, Black);
        cv::putText(textCanvas, text.value , text.textOrg, text.fontType, text.fontScale, color, text.textThickness); // 5. insert Text operation 
        tools::insertIntoRegion(canvas, textCanvas, x, y, TextScale); 
    }
    if(personFlag){
        cv::Mat personTextCanvas(logo_orignal.rows, logo_orignal.cols, CV_8UC3, Black);
        cv::putText(personTextCanvas, "Ziyang Zhang from ZJU" , text.textOrg, text.fontType, text.fontScale, color, text.textThickness); // 5. insert Text operation
        tools::insertIntoRegion(canvas, personalImage, x*(-1), 0, PersonImageScale);
        tools::insertIntoRegion(canvas, personTextCanvas, x*(-1), y, TextScale);
    }
    // display
    tools::showCurrentPics(windowName, canvas);
    // save operation
    tools::save(canvas, outputDir, timeStep);
    return canvas;    

}