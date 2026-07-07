# setup.skill.md

이 스킬은 개발 환경 설치 및 구성 관련된 구체적인 단계와 명령을 제공합니다. `setup-manager` 에이전트가 호출하여 시스템에 필요한 패키지와 도구를 설치하도록 설계되었습니다.

목차:
- 시스템 검사
- 패키지 설치 (apt)
- vcpkg 설치 및 부트스트랩
- OpenCV/Qt 설치 지침
- VS Code 설정
- 검증 명령 모음

## 사용 예
`setup-manager` 에이전트는 다음과 같이 이 스킬을 호출합니다:

1. 시스템 검사
```bash
lsb_release -a
free -h
df -h
```

2. 필수 패키지 설치
```bash
sudo apt update && sudo apt upgrade -y
sudo apt install -y build-essential cmake git wget curl pkg-config ninja-build \
  gdb valgrind clang-format clang-tidy qt6-base-dev libopencv-dev docker.io
```

3. vcpkg 설치
```bash
cd /opt
sudo git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
sudo ./bootstrap-vcpkg.sh
```

4. VS Code 확장 설치
```bash
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
code --install-extension eamodio.gitlens
```

5. 검증
```bash
g++ --version
cmake --version
qmake --version
pkg-config --modversion opencv4
vcpkg version
```
