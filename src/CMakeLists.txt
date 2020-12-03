include_directories(${PROJECT_SOURCE_DIR}/include)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(tool_library tools.cpp)

add_library(sceneOne_library sceneOne.cpp)

add_executable( play main.cpp )

target_link_libraries( play tool_library sceneOne_library ${OpenCV_LIBS} )


