#include "fundation.hpp"

namespace tools{
    // show the picture
    void showCurrentPics(char*, cv::Mat, int = 1);
    // insert param2 into param1. default location is center or plus x,y transform
    void insertIntoRegion(cv::Mat&, cv::Mat, int = 0, int = 0, double = 1.0);
    // set the color
    cv::Mat colorized(int, int, double, double, double); 
    // scene Transitions
    void sceneTransistion(int, int, char*, cv::Mat, std::string, int&);
    // save images
    void save(cv::Mat, std::string, int&);
    // produce video from exsited images fold
    void produceVideo(std::string, int);
}// namespace display