#include "video_player.h"
#include <iostream>

int main(int argc , char** argv) {

    VideoProcessor::VideoPlayer player("../test.mp4");
    player.run();

    return 0;
}
