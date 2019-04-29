#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <string>
#include <opencv2/videoio.hpp>

namespace VideoProcessor  {


    class VideoPlayer {

        public:

            VideoPlayer(const std::string& path , const std::string& window_name = "Video Player");
            virtual ~VideoPlayer() {}

            void run();

        protected:

            virtual void process() {}

            cv::VideoCapture cap;
            bool running;
            std::string window_name;

            void show_frame(const cv::Mat& frame);
    };

};


#endif
