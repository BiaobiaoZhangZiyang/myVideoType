#include "tools.hpp"

// scene 1
namespace scene1{
    struct sceneText{
        double fontScale;
        int textThickness;
        int fontType;
        std::string value;
        cv::Size textSize;
        cv::Point textOrg;
    };
    cv::Mat sceneOne(std::string, std::string, char*, int&);
    cv::Mat subScene(cv::Mat, cv::Mat, cv::Scalar, struct scene1::sceneText, int, int, bool, std::string, char*, int&, bool = false);
} // namespace sceneOne