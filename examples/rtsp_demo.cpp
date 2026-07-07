#include "rtsp_client.h"
#include <iostream>
#ifdef HAS_OPENCV
#include <opencv2/opencv.hpp>
#endif

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: rtsp_demo <rtsp-url-or-file>\n";
        return 1;
    }

    std::string url = argv[1];
    agentic::RTSPClient client;

    if (!client.open(url)) {
        std::cerr << "Failed to open stream: " << url << std::endl;
        return 2;
    }

#ifdef HAS_OPENCV
    cv::Mat frame;
    while (true) {
        if (!client.readFrame(&frame)) {
            std::cerr << "Frame read failed or stream ended." << std::endl;
            break;
        }
        cv::imshow("RTSP Demo", frame);
        if (cv::waitKey(1) == 27) break; // ESC
    }
#else
    std::cerr << "OpenCV not available in this build. Cannot display stream." << std::endl;
#endif

    client.close();
    return 0;
}
