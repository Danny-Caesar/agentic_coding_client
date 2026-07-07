#!/usr/bin/env bash
set -euo pipefail

# 설치 위치
VCPKG_DIR=/opt/vcpkg

echo "Installing vcpkg to ${VCPKG_DIR} (requires sudo)"
sudo mkdir -p ${VCPKG_DIR}
sudo chown $(whoami):$(whoami) ${VCPKG_DIR}

cd /opt
if [ -d "vcpkg" ]; then
  echo "vcpkg already cloned"
else
  git clone https://github.com/Microsoft/vcpkg.git
fi
cd vcpkg
./bootstrap-vcpkg.sh

echo "vcpkg installed. Add /opt/vcpkg to PATH if desired."
