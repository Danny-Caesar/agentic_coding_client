#include "rtsp_client.h"
#include <gtest/gtest.h>

using namespace agentic;

TEST(RTSPClientTest, OpenInvalidURLReturnsFalse) {
    RTSPClient c;
    EXPECT_FALSE(c.open("invalid://url"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
