#include "video_brightener.h"

#include <opencv2/highgui.hpp>
#include <iostream>

namespace VideoProcessor {

    VideoBrightener::VideoBrightener(const std::string& path , int brightness , int frame_rate):
        cap(path),
        brightness(brightness) ,
        frame_rate(frame_rate) {

        if(!cap.isOpened()) {
            std::cerr << "Error loading " << path << "\n";
            exit(1);
        }

        running = true;
    }

    void VideoBrightener::run() {
        
        cv::Mat frame;
        cv::Mat processed_frame;

        int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
        int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

        cv::VideoWriter writer("output.avi" ,
                cv::VideoWriter::fourcc('M' , 'J' , 'P' , 'G'),
                frame_rate,
                cv::Size(frame_width , frame_height));

        while(running) {

            cap >> frame;

            if(frame.empty()) {
                running = false;
                continue;
            }

            process(frame , processed_frame);
            show_frame(frame , "Original");
            show_frame(processed_frame , "Brighter");
            writer.write(processed_frame);


            if(char(cv::waitKey(1)) == 'q')
                running = false;

        }

        std::cout << "Complete.\n";
    }

    void VideoBrightener::show_frame(const cv::Mat& frame , const std::string& name) {

        cv::namedWindow(name, cv::WINDOW_NORMAL);
        cv::imshow(name, frame);
    }

    
    void VideoBrightener::process(const cv::Mat& frame , cv::Mat& processed_frame) {

        processed_frame = frame.clone();
        processed_frame.convertTo(processed_frame , -1 , 1 , brightness);
    }
}
