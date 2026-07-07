#pragma once

#include <string>
#ifdef HAS_OPENCV
#include <opencv2/opencv.hpp>
#endif

namespace agentic {

class RTSPClient {
public:
    RTSPClient();
    ~RTSPClient();

    // Open a stream URL (rtsp://... or file)
    bool open(const std::string &url);

    // Read next frame into provided Mat. Returns true if frame read.
    bool readFrame(/* out */ void* frame);

    // Close the stream
    void close();

private:
#ifdef HAS_OPENCV
    cv::VideoCapture cap_;
#endif
    bool opened_ = false;
};

} // namespace agentic
