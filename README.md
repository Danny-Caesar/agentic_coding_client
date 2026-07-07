# Agentic Coding Client - Development

This repository contains the client-side components for the Agentic Coding camera monitoring system.

Build prerequisites (Ubuntu):

- C++17 compiler (g++)
- CMake >= 3.16
- OpenCV (optional but required for RTSP demo)
- Google Test (optional for unit tests)

Build instructions:

```bash
mkdir -p build && cd build
cmake .. -DUSE_OPENCV=ON
cmake --build .
```

Run RTSP demo:

```bash
./rtsp_demo rtsp://<your-stream-url>
```

Run tests (if GTest found during CMake):

```bash
ctest --output-on-failure
```

Notes:
- If OpenCV is not installed, the demo will be built but will fail at runtime with a message.
- Use `agent/scripts/setup_env.sh` and `agent/scripts/setup_vcpkg.sh` to prepare a development environment.
