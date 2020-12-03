#include "sceneTwo.hpp"

void scene2::movingFlashLight(){
    cv::Mat canvas(Height, Width, CV_8UC3, Black);

    // 随着聚光灯移动，画一个矩形
    int y = canvas.cols / 2 - 50;
    for(int x_bias = 0; x_bias < 50; x_bias++){
        cv::Mat mask(Height, Width, CV_8UC3, Black);
        int x = canvas.rows/2 + x_bias;
        circle(canvas, cv::Point(x, y), 25, cv::Scalar(0.0, 255.0, 255.0), 3);
    }

    // 然后在生成几个矩形
    
}