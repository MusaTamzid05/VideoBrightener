#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <string>
#include <opencv2/videoio.hpp>

namespace VideoProcessor  {


    class VideoPlayer {

        public:

            VideoPlayer(const std::string& path , int brightness , int frame_rate = 24);
            virtual ~VideoPlayer() {}

            void run();

        private:


            void process(const cv::Mat& frame , cv::Mat& processed_frame);
            void show_frame(const cv::Mat& frame , const std::string& name);

            cv::VideoCapture cap;
            bool running;
            int brightness;

            int frame_rate;

    };

};


#endif
