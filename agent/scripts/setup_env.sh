#!/usr/bin/env bash
set -euo pipefail

# 기본 개발 패키지 설치 스크립트 (Ubuntu)
sudo apt update && sudo apt upgrade -y
sudo apt install -y \
  build-essential cmake git wget curl pkg-config ninja-build \
  gdb valgrind clang-format clang-tidy \
  qt6-base-dev libopencv-dev docker.io code

# Optional: add current user to docker group
sudo usermod -aG docker $(whoami) || true

echo "Base development packages installed. Please log out/in if docker group was updated."
