#include "sceneThree.hpp"

void scene3::theEnd(std::string outputDir, char* windowName, int& timeStep){
    /* ---------------------------------- Text -------------------------------------------*/
    double fontScale = 2.0;
    int textThickness = 3;
    int fontType = cv::FONT_HERSHEY_COMPLEX;
    std::string value = "The End, generating video ...";
    cv::Size textSize = cv::getTextSize(value, fontType, fontScale, textThickness, 0);
    cv::Point textOrg = cv::Point(0, Height/2);

    cv::Mat lastScene(Height, Width, CV_8UC3, Black); 
    cv::putText(lastScene, value, textOrg, fontType, fontScale, White, textThickness);
    tools::showCurrentPics(windowName, lastScene);
    tools::save(lastScene, outputDir, timeStep);
}