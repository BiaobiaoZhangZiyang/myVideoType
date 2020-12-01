#include "fundation.hpp"

namespace tools{
    // show the picture
    void showCurrentPics(char*, cv::Mat);
    void insertIntoRegion(cv::Mat&, cv::Mat, int = 0, int = 0, double = 1.0);
    cv::Mat colorized(int, int, double, double, double); 
}// namespace display