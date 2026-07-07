#include "rtsp_client.h"
#include <iostream>

namespace agentic {

RTSPClient::RTSPClient() = default;
RTSPClient::~RTSPClient() { close(); }

bool RTSPClient::open(const std::string &url) {
#ifdef HAS_OPENCV
    cap_.open(url);
    opened_ = cap_.isOpened();
    if (!opened_) {
        std::cerr << "RTSPClient: failed to open " << url << std::endl;
    }
    return opened_;
#else
    (void)url;
    std::cerr << "RTSPClient: OpenCV not available in this build." << std::endl;
    return false;
#endif
}

bool RTSPClient::readFrame(void* frame) {
#ifdef HAS_OPENCV
    if (!opened_) return false;
    cv::Mat* mat = static_cast<cv::Mat*>(frame);
    return static_cast<bool>(cap_.read(*mat));
#else
    (void)frame;
    return false;
#endif
}

void RTSPClient::close() {
#ifdef HAS_OPENCV
    if (cap_.isOpened()) cap_.release();
#endif
    opened_ = false;
}

} // namespace agentic
