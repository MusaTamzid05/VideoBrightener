#include "video_player.h"
#include <iostream>

int main(int argc , char** argv) {

    if(argc != 2) {
        std::cerr << "Usage: video_path <brightness>\n";
        exit(1);
    }


    std::string path = argv[1];
    int brightness;

    if(argc == 3)
        brightness = std::stoi(argv[2]);
    else
        brightness = 50;


    VideoProcessor::VideoPlayer player(path , brightness);
    player.run();

    return 0;
}
