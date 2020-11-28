#include "tools.hpp"

int main(){
    char windowName[] = "Test";
    cv::Mat canvas = cv::Mat::ones(Height, Width, CV_8UC3);
    cv::Mat logo_orignal = cv::imread("/home/zzy/Desktop/myVideoType/pics/zju_orignal.png", 1);
    std::cout<<logo_orignal.cols<<"\n";
    std::cout<<logo_orignal.rows<<"\n";
    cv::Mat lookUpTable(1, 256, CV_8U);
    // 遍历？
    // uchar* p = lookUpTable.ptr();
    // for(int i = 0;i<256)
    tools::insertIntoRegion(canvas, logo_orignal, 0.5); 
    tools::showCurrentPics(windowName, canvas);
    return 0;
}
