cmake_minimum_required(VERSION 2.8)
project(VideoBrighter)


SET(OpenCV_DIR "your opencv build path")
SET( OpenCV_FOUND TRUE)
find_package(OpenCV REQUIRED)

set(SOURCE_FILES
    src/main.cpp
    src/video_brightener.cpp
    )


include_directories(include)
add_executable(VideoBrighter ${SOURCE_FILES})
target_link_libraries(VideoBrighter ${OpenCV_LIBS})
