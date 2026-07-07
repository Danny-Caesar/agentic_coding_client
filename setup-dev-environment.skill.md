# Development Environment Setup Skill

## Overview
This skill provides step-by-step instructions for setting up the complete development environment for the Agentic Coding Client project, including all required tools, libraries, and VS Code configuration.

## Table of Contents
1. [System Requirements](#system-requirements)
2. [Prerequisites](#prerequisites)
3. [Ubuntu/WSL2 Setup](#ubuntuwsl2-setup)
4. [Development Tools Installation](#development-tools-installation)
5. [C++ Development Environment](#c-development-environment)
6. [Qt Framework Setup](#qt-framework-setup)
7. [OpenCV Installation](#opencv-installation)
8. [VS Code Configuration](#vs-code-configuration)
9. [vcpkg Setup](#vcpkg-setup)
10. [Project Build Configuration](#project-build-configuration)
11. [Verification Checklist](#verification-checklist)

---

## System Requirements

### Minimum Specifications
- **OS**: Ubuntu 20.04 LTS or newer (or WSL2 with Ubuntu)
- **RAM**: 4GB minimum (8GB recommended)
- **Storage**: 10GB free space (20GB recommended for dependencies)
- **Internet**: Required for package downloads

### OS Detection
```bash
# Check OS version
lsb_release -a

# For WSL2, verify version
wsl --list --verbose
```

---

## Prerequisites

### 1. Update System Packages
```bash
sudo apt update
sudo apt upgrade -y
```

### 2. Install Essential Build Tools
```bash
sudo apt install -y \
  build-essential \
  cmake \
  git \
  wget \
  curl \
  pkg-config \
  autoconf \
  automake \
  libtool \
  ninja-build
```

### 3. Install Additional Development Tools
```bash
sudo apt install -y \
  gdb \
  valgrind \
  clang \
  clang-format \
  clang-tidy \
  lldb
```

---

## Ubuntu/WSL2 Setup

### For Native Ubuntu

#### Installation Steps
```bash
# 1. Update package manager
sudo apt update && sudo apt upgrade -y

# 2. Install basic development environment
sudo apt install -y build-essential cmake

# 3. Verify installation
gcc --version
cmake --version
```

### For WSL2 on Windows

#### Pre-requisites
- Windows 10/11 with WSL2 enabled
- Ubuntu 20.04 LTS or newer installed on WSL2

#### WSL2 Configuration
```bash
# Install Ubuntu from Windows Store or use:
wsl --install -d Ubuntu-22.04

# Set WSL2 as default version
wsl --set-version Ubuntu-22.04 2

# Verify WSL2 version
wsl --list --verbose
```

#### GUI Support for Qt (Optional)
```bash
# For X11 forwarding in WSL2
sudo apt install -y x11-apps
export DISPLAY=:0
```

---

## Development Tools Installation

### 1. GCC/G++ Compiler
```bash
# Install GCC 11 (or latest)
sudo apt install -y g++ gcc

# Install GCC 12+ for better C++20 support
sudo apt install -y gcc-12 g++-12
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 100
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 100

# Verify
g++ --version
```

### 2. CMake Installation
```bash
# Option 1: Install from Ubuntu repositories (may be older)
sudo apt install -y cmake

# Option 2: Install latest CMake from source (Recommended)
cd /tmp
wget https://github.com/Kitware/CMake/releases/download/v3.27.0/cmake-3.27.0-linux-x86_64.tar.gz
tar xzf cmake-3.27.0-linux-x86_64.tar.gz
sudo mv cmake-3.27.0-linux-x86_64 /opt/cmake
sudo ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake
cmake --version
```

### 3. Git Configuration
```bash
# Install Git
sudo apt install -y git

# Configure Git
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# Verify
git --version
```

### 4. GDB Debugger
```bash
# Install GDB
sudo apt install -y gdb

# Verify
gdb --version
```

---

## C++ Development Environment

### 1. Standard Library Support
```bash
# Install C++ standard library
sudo apt install -y libstdc++-12-dev

# For additional C++ libraries
sudo apt install -y libc++-dev libc++abi-dev
```

### 2. LLVM/Clang Toolchain
```bash
# Install Clang
sudo apt install -y clang clang-tools

# Install LLVM
sudo apt install -y llvm llvm-dev

# Verify
clang --version
llvm-config --version
```

### 3. Boost Libraries (Optional)
```bash
# Install Boost
sudo apt install -y libboost-all-dev

# Verify installation
dpkg -l | grep libboost
```

---

## Qt Framework Setup

### 1. Install Qt Development Files
```bash
# Install Qt5 development files
sudo apt install -y \
  qt5-default \
  qt5-qmake \
  qtbase5-dev \
  qtchooser \
  libqt5core5a \
  libqt5gui5 \
  libqt5widgets5

# For Qt6 (newer, recommended)
sudo apt install -y \
  qt6-base-dev \
  qt6-tools-dev \
  libqt6core6 \
  libqt6gui6 \
  libqt6widgets6
```

### 2. Qt Tools
```bash
# Install Qt tools
sudo apt install -y \
  qt5-assistant \
  qt5-doc \
  qtbase5-examples

# Install Designer (GUI design tool)
sudo apt install -y qt5-designer
```

### 3. Qt CMake Support
```bash
# Install Qt CMake modules
sudo apt install -y \
  cmake-qt5-gui \
  qt5-cmake-standalone

# For Qt6
sudo apt install -y qt6-cmake
```

### 4. Verify Qt Installation
```bash
# Check Qt version
qmake --version

# or for Qt6
qt-cmake --version

# List installed Qt modules
qtpaths --binaries
```

---

## OpenCV Installation

### 1. Install OpenCV from Repository (Quick Method)
```bash
# Install OpenCV libraries
sudo apt install -y \
  libopencv-dev \
  python3-opencv \
  opencv-data

# Verify
pkg-config --modversion opencv4
```

### 2. Build OpenCV from Source (Recommended for Latest Features)
```bash
# Install dependencies
sudo apt install -y \
  build-essential \
  cmake \
  git \
  libgtk-3-dev \
  libatlas-base-dev \
  libjasper-dev \
  libtiff5-dev \
  libharfbuzz0b \
  libwebp6 \
  libjasper1 \
  libjpeg-turbo-progs \
  libatlas3-base

# Clone OpenCV repository
cd /opt
sudo git clone https://github.com/opencv/opencv.git
cd opencv
sudo git checkout 4.8.0  # Use latest stable version

# Build OpenCV
sudo mkdir -p build
cd build
sudo cmake -D CMAKE_BUILD_TYPE=Release \
  -D CMAKE_INSTALL_PREFIX=/usr/local \
  -D WITH_TBB=ON \
  -D WITH_V4L=ON \
  -D WITH_QT=ON \
  -D WITH_OPENGL=ON \
  ..

# Compile (this may take 30-60 minutes)
sudo make -j$(nproc)

# Install
sudo make install
sudo ldconfig
```

### 3. Verify OpenCV Installation
```bash
# Verify installation
pkg-config --modversion opencv4
pkg-config --cflags --libs opencv4
```

---

## VS Code Configuration

### 1. Install VS Code
```bash
# Download and install VS Code
sudo apt update
sudo apt install -y software-properties-common apt-transport-https
curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64 signed-by=/etc/apt/trusted.gpg.d/microsoft.gpg] https://packages.microsoft.com/repos/vscode stable main" > /etc/apt/sources.list.d/vscode.list'
sudo apt update
sudo apt install -y code
```

### 2. Install Essential Extensions
```bash
# C++ extension
code --install-extension ms-vscode.cpptools

# C++ Intellisense
code --install-extension ms-vscode.cpptools-extension-pack

# CMake Tools
code --install-extension ms-vscode.cmake-tools

# CMake Language Support
code --install-extension twxs.cmake

# Clang-Format
code --install-extension xaver.clang-format

# GitLens
code --install-extension eamodio.gitlens

# Qt Tools
code --install-extension ms-vscode.qt-tools

# Docker support (Optional)
code --install-extension ms-azuretools.vscode-docker

# GitHub Copilot
code --install-extension GitHub.copilot

# Google Test Adapter
code --install-extension ms-vscode.gtest
```

### 3. VS Code Settings
Create or update `.vscode/settings.json`:
```json
{
  "[cpp]": {
    "editor.defaultFormatter": "xaver.clang-format",
    "editor.formatOnSave": true,
    "editor.insertSpaces": true,
    "editor.tabSize": 4
  },
  "C_Cpp.intelliSenseEngine": "Tag Parser",
  "C_Cpp.codeAnalysis.clangTidy.enabled": true,
  "C_Cpp.clang_format_path": "/usr/bin/clang-format",
  "C_Cpp.clang_format_style": "file",
  "cmake.buildDirectory": "${workspaceFolder}/build",
  "cmake.generator": "Ninja",
  "cmake.preferredGenerators": ["Ninja", "Unix Makefiles"],
  "files.exclude": {
    "**/.git": true,
    "**/build": true,
    "**/CMakeFiles": true
  },
  "search.exclude": {
    "build": true,
    "CMakeFiles": true
  }
}
```

### 4. Launch Configuration
Create `.vscode/launch.json`:
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "C++ Debug",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/build/agentic_client",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "Build",
      "miDebuggerPath": "/usr/bin/gdb"
    }
  ]
}
```

### 5. Build Task Configuration
Create `.vscode/tasks.json`:
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build",
      "type": "shell",
      "command": "cmake",
      "args": [
        "--build",
        "${workspaceFolder}/build"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"]
    },
    {
      "label": "Configure",
      "type": "shell",
      "command": "cmake",
      "args": [
        "-B",
        "${workspaceFolder}/build",
        "-S",
        "${workspaceFolder}",
        "-G",
        "Ninja"
      ]
    },
    {
      "label": "Clean",
      "type": "shell",
      "command": "rm",
      "args": [
        "-rf",
        "${workspaceFolder}/build"
      ]
    }
  ]
}
```

---

## vcpkg Setup

### 1. Install vcpkg
```bash
# Clone vcpkg repository
cd /opt
sudo git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg

# Bootstrap vcpkg
sudo ./bootstrap-vcpkg.sh

# Add vcpkg to PATH (add to ~/.bashrc or ~/.zshrc)
echo 'export PATH="/opt/vcpkg:$PATH"' >> ~/.bashrc
source ~/.bashrc

# Verify installation
vcpkg version
```

### 2. Install Project Dependencies via vcpkg
```bash
# List available ports
vcpkg search

# Install specific packages
vcpkg install opencv:x64-linux
vcpkg install qt:x64-linux
vcpkg install gtest:x64-linux
vcpkg install ffmpeg:x64-linux
```

### 3. Create vcpkg.json for Project
```json
{
  "name": "agentic-client",
  "version": "1.0.0",
  "dependencies": [
    "opencv",
    "qt",
    "gtest",
    "ffmpeg"
  ]
}
```

### 4. Configure CMake to Use vcpkg
```bash
# When building, use vcpkg toolchain:
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake
```

---

## Project Build Configuration

### 1. Create CMakeLists.txt Template
```cmake
cmake_minimum_required(VERSION 3.16)
project(agentic_client CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find required packages
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(GTest REQUIRED)

# Source files
set(SOURCES
  src/main.cpp
  src/mainwindow.cpp
  src/videostreamer.cpp
)

set(HEADERS
  include/mainwindow.h
  include/videostreamer.h
)

# Executable
add_executable(agentic_client ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(agentic_client
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  ${OpenCV_LIBS}
)

# Include directories
target_include_directories(agentic_client PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
)

# Enable testing
enable_testing()
add_executable(tests tests/test_main.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)
add_test(NAME AllTests COMMAND tests)
```

### 2. Project Directory Structure
```
agentic_coding_client/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   └── videostreamer.cpp
├── include/
│   ├── mainwindow.h
│   └── videostreamer.h
├── tests/
│   └── test_main.cpp
├── resources/
│   └── resources.qrc
├── build/  (created by CMake)
└── .vscode/
    ├── settings.json
    ├── launch.json
    └── tasks.json
```

---

## Verification Checklist

### System Tools
- [ ] GCC/G++ installed: `g++ --version`
- [ ] CMake installed: `cmake --version`
- [ ] Git configured: `git config --global user.name`
- [ ] GDB installed: `gdb --version`

### Development Libraries
- [ ] Qt installed: `qmake --version` or `qt-cmake --version`
- [ ] OpenCV installed: `pkg-config --modversion opencv4`
- [ ] Google Test installed: `dpkg -l | grep gtest`

### VS Code Configuration
- [ ] VS Code installed: `code --version`
- [ ] C++ extensions installed: Check Extensions panel
- [ ] CMake extensions installed: Check Extensions panel
- [ ] Workspace settings configured: `.vscode/settings.json` exists

### vcpkg Setup
- [ ] vcpkg installed: `vcpkg version`
- [ ] Project dependencies listed: `vcpkg.json` exists
- [ ] Dependencies installed: `vcpkg list`

### Project Build
- [ ] CMakeLists.txt created
- [ ] Build directory: `mkdir build && cd build`
- [ ] Configure: `cmake -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake ..`
- [ ] Build: `cmake --build .`
- [ ] Executable created: Binary exists in build directory

### Final Verification
```bash
# Test build process
cd build
cmake ..
make
./agentic_client --version

# Run tests
ctest
```

---

## Troubleshooting

### Issue: Qt not found in CMake
```bash
# Solution: Install Qt CMake modules
sudo apt install -y qt6-cmake

# Or set Qt path explicitly in CMake
cmake .. -DQt6_DIR=/usr/lib/cmake/Qt6
```

### Issue: OpenCV not found
```bash
# Solution: Set PKG_CONFIG_PATH
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH

# Or use OpenCV_DIR in CMake
cmake .. -DOpenCV_DIR=/usr/local/lib/cmake/opencv4
```

### Issue: GDB not finding symbols
```bash
# Solution: Compile with debug symbols
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

### Issue: VS Code not recognizing includes
```bash
# Solution: Update C++ include paths in settings.json
"C_Cpp.default.includePath": [
  "${workspaceFolder}/include",
  "/usr/include/opencv4",
  "/usr/include/qt6"
]
```

---

## Post-Installation Steps

### 1. Clone Project Repository
```bash
cd ~/projects
git clone https://github.com/Danny-Caesar/agentic_coding_client.git
cd agentic_coding_client
```

### 2. Initialize Build Directory
```bash
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake ..
cmake --build .
```

### 3. Verify Installation
```bash
# Run built executable
./agentic_client

# Run tests
ctest
```

### 4. Open in VS Code
```bash
cd ..
code .
```

---

**Documentation Version**: 1.0  
**Last Updated**: 2026-07-07  
**Maintained By**: Agentic Coding Team
