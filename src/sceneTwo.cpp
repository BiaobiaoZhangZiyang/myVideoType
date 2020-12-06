#include "sceneTwo.hpp"

cv::Mat scene2::randomCircles(char* windowName, std::string outputPath, int& timeStep){
    static std::default_random_engine e;
    e.seed(time(0));
    static std::uniform_int_distribution<unsigned> fx(0, Width);
    static std::uniform_int_distribution<unsigned> fy(0, Height);
    static std::uniform_int_distribution<unsigned> r(10, 100);
    cv::Mat canvas(Height, Width, CV_8UC3, Black);

    // randomly draw random circle
    for(int i = 0; i < 500; i++){
        int x = fx(e);  // x coordinate
        int y = fy(e); // y coordinate
        int radius = r(e); // radius
        switch(i%7){
            case 0:
                circle(canvas, cv::Point(x, y), radius, Red, -1);
                break;
            case 1:
                circle(canvas, cv::Point(x, y), radius, Orange, -1);
                break;
            case 2:
                circle(canvas, cv::Point(x, y), radius, Yellow, -1);
                break;
            case 3:
                circle(canvas, cv::Point(x, y), radius, Green, -1);
                break;
            case 4:
                circle(canvas, cv::Point(x, y), radius, Blue, -1);
                break;
            case 5:
                circle(canvas, cv::Point(x, y), radius, Purple, -1);
                break;
            case 6:
                circle(canvas, cv::Point(x, y), radius, White, -1);
                break;
        }
        tools::save(canvas, outputPath, timeStep);
        tools::showCurrentPics(windowName, canvas);
    }    
    return canvas;
}