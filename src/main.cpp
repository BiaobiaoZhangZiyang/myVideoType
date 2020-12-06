#include "sceneOne.hpp"
#include "sceneTwo.hpp"

int main(int argc, char* argv[]){
    int timeStep = 0;
    if(argc < 3)
    {
        std::cout<<"Usage:"<<std::endl;
        std::cout<<"play inputImage_dir output_video_dir"<<std::endl;
        return -1;
    }

    // load path setUp
    std::string inputDir = argv[1];
    std::string outputDir = argv[2];
    // Window setUp
    char windowName[] = "MyVideoType  -- from zzy 20201203";
    try{
        // SCENE ONE: Me and ZJU
        /* ---------------------------------- Scene 1 --------------------------------------------*/
        /*
        cv::Mat sceneOneLastScrenShot(Width, Height, CV_8UC3, Black); // scene 1 last sceneshot
        scene1::sceneOne(inputDir, outputDir, windowName, timeStep).copyTo(sceneOneLastScrenShot);

        // ===> ************** screen transation ***************** <====
        tools::showCurrentPics(windowName, sceneOneLastScrenShot, 2);
        tools::save(sceneOneLastScrenShot, outputDir, timeStep);
        tools::sceneTransistion(Height, Width, windowName, sceneOneLastScrenShot, outputDir, timeStep);
        */
        // SCENE TWO: Tell a story
        /* ---------------------------------- Scene 2 --------------------------------------------*/
        cv::Mat sceneTwoLastScrenShot(Width, Height, CV_8UC3, Black); // scene 2 last sceneshot
        scene2::randomCircles(windowName, outputDir, timeStep).copyTo(sceneTwoLastScrenShot);
        // ===> ************** screen transation ***************** <====
        //tools::sceneTransistion2(sceneTwoLastScrenShot, windowName, outputDir, timeStep);
        tools::sceneTransistion(Height, Width, windowName, sceneTwoLastScrenShot, outputDir, timeStep);
        // produce a movie 
        tools::produceVideo(outputDir, timeStep);
    }catch (const std::exception e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}
