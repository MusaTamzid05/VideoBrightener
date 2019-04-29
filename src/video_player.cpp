#include "video_player.h"

#include <opencv2/highgui.hpp>
#include <iostream>

namespace VideoProcessor {

    VideoPlayer::VideoPlayer(const std::string& path , const std::string& window_name):
        cap(path) ,
        window_name(window_name) {

        if(!cap.isOpened()) {
            std::cerr << "Error loading " << path << "\n";
            exit(1);
        }

        running = true;
    }

    void VideoPlayer::run() {

        while(running) {

            cv::Mat frame;
            cap >> frame;

            if(frame.empty()) {
                running = false;
                continue;
            }

            show_frame(frame);

            if(char(cv::waitKey(4)) == 'q')
                running = false;

        }
    }

    void VideoPlayer::show_frame(const cv::Mat& frame) {

        cv::namedWindow(window_name , cv::WINDOW_NORMAL);
        cv::imshow(window_name , frame);
    }
}
