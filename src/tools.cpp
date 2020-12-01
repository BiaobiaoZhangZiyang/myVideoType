#include "tools.hpp"

void tools::showCurrentPics(char* windowName, cv::Mat image){
    cv::imshow(windowName, image); // 1. fundmantal images show line 4-5
    cv::waitKey( 1 );
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