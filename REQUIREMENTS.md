# 요구사항 명세서 (Requirements Specification)

## 1. 개요 (Overview)

### 1.1 프로젝트 개요
카메라 관제 시스템은 클라이언트-서버 구조로 설계된 실시간 비디오 스트리밍 및 카메라 제어 시스템입니다.

**프로젝트명**: 아젠틱 코딩 서버 (Agentic Coding Server)  
**목표**: 카메라 관제 시스템 개발  
**아키텍처**: Client-Server 구조

### 1.2 시스템 개요
- 원격 서버에서 비디오 스트림을 수신하는 클라이언트 애플리케이션
- 클라이언트로부터 명령을 수신하여 카메라를 제어하는 서버 애플리케이션
- RTSP/H.264를 통한 효율적인 비디오 전송
- Qt 기반 사용자 인터페이스

---

## 2. 클라이언트 (Client) 요구사항

### 2.1 기능 요구사항 (Functional Requirements)

#### 2.1.1 서버 연결 기능
- **다중 명령어 송출**: 클라이언트는 서버에 다양한 명령어를 송출할 수 있어야 함
  - 접속 명령 (Connection Command)
  - 접속 해제 명령 (Disconnection Command)
  - 추가 제어 명령

#### 2.1.2 화면 제어 기능
- **화면 제어**: 서버의 카메라 화면을 원격으로 제어
  - Frame Rate 조절 (프레임 레이트 제어)
  - Resolution 조절 (해상도 제어)
  - 실시간 조정 가능

#### 2.1.3 비디오 스트리밍
- **비디오 수신**: 서버로부터 송출되는 비디오 스트리밍을 수신 및 재생
  - H.264 코덱 지원
  - RTSP 프로토콜 지원
  - 실시간 비디오 디스플레이

#### 2.1.4 에러 처리
- **에러 메시지 표출**: 문제 발생 시 화면에 명확한 에러 메시지를 표출
  - 연결 오류 처리
  - 스트리밍 오류 처리
  - 명령 전송 오류 처리

### 2.2 운영 환경 (Runtime Environment)

| 항목 | 사양 |
|------|------|
| **OS** | Ubuntu |
| **패키지 관리** | vcpkg/Docker |
| **서버 인터페이스** | RTSP/H.264 |
| **UI Framework** | Qt (QT) |

### 2.3 개발 환경 (Development Environment)

| 항목 | 사양 |
|------|------|
| **OS** | Ubuntu / Windows Subsystem for Linux 2 (WSL2) |
| **IDE** | VS Code / Copilot, Codex or Claude |
| **프로그래밍 언어** | C++ |
| **빌드 도구** | CMake |
| **패키지 관리** | vcpkg |
| **컴파일러** | g++ |
| **디버깅 도구** | gdb |
| **비전 라이브러리** | OpenCV |
| **UI Framework** | Qt |
| **테스트 프레임워크** | Google Test |
| **배포** | Docker |

---

## 3. 서버 요구사항

### 3.1 기능 요구사항 (Functional Requirements)

#### 3.1.1 클라이언트 명령 처리
- 클라이언트로부터 수신한 명령어를 처리
- 접속/접속 해제 관리
- 카메라 화면 제어 명령 처리

#### 3.1.2 카메라 제어
- **Frame Rate**: 프레임 레이트 조절 기능
- **Resolution**: 해상도 조절 기능
- 실시간 설정 변경 적용

#### 3.1.3 비디오 스트리밍 서버
- RTSP 프로토콜을 통한 비디오 스트리밍
- H.264 비디오 코덱 지원
- 다중 클라이언트 동시 연결 지원 (필요 시)

#### 3.1.4 에러 처리
- 클라이언트에 에러 메시지 전송
- 연결 오류 처리
- 카메라 오류 처리

### 3.2 운영 환경 (Runtime Environment)

| 항목 | 사양 |
|------|------|
| **OS** | Ubuntu |
| **패키지 관리** | vcpkg/Docker |
| **서버 인터페이스** | RTSP/H.264 |

### 3.3 개발 환경 (Development Environment)

| 항목 | 사양 |
|------|------|
| **OS** | Ubuntu / WSL2 |
| **IDE** | VS Code / Copilot, Codex or Claude |
| **프로그래밍 언어** | C++ |
| **빌드 도구** | CMake |
| **패키지 관리** | vcpkg |
| **컴파일러** | g++ |
| **디버깅 도구** | gdb |
| **비전 라이브러리** | OpenCV |
| **테스트 프레임워크** | Google Test |
| **배포** | Docker |

---

## 4. 시스템 아키텍처

### 4.1 Client-Server 구조

```
┌─────────────────┐                    ┌─────────────────┐
│  Client (Qt UI) │◄──────RTSP────────►│  Server         │
│                 │  (H.264 Video)     │  (Camera Ctrl)  │
│ - Commands      │                    │                 │
│ - UI Display    │◄──────Commands────►│ - Camera Stream │
│ - Error Display │   (TCP/Socket)     │ - Settings      │
└─────────────────┘                    └─────────────────┘
```

### 4.2 통신 프로토콜

- **비디오 스트리밍**: RTSP (Real Time Streaming Protocol)
- **비디오 코덱**: H.264
- **명령 전송**: TCP/Socket 기반 커스텀 프로토콜

---

## 5. 기술 스택

### 5.1 필수 라이브러리

| 라이브러리 | 목적 | 버전 |
|-----------|------|------|
| **OpenCV** | 비디오 캡처 및 처리 | Latest Stable |
| **Qt** | 사용자 인터페이스 | Latest Stable |
| **FFmpeg (또는 libav)** | 비디오 인코딩/디코딩 | Latest Stable |
| **Google Test** | 단위 테스트 | Latest Stable |

### 5.2 빌드 및 배포

- **빌드 자동화**: CMake
- **패키지 관리**: vcpkg
- **컨테이너화**: Docker
- **배포**: Docker Image

---

## 6. 비기능 요구사항

### 6.1 성능 (Performance)
- 비디오 스트리밍 지연: < 500ms (권장)
- 명령 응답 시간: < 100ms
- 프레임 레이트: 최소 24 FPS

### 6.2 신뢰성 (Reliability)
- 연결 끊김 시 자동 재연결 시도
- 에러 로깅 및 상세 에러 메시지
- 안정적인 비디오 스트림 전송

### 6.3 확장성 (Scalability)
- 다중 클라이언트 동시 연결 지원 (서버 성능에 따름)
- 모듈화된 설계로 기능 확장 용이

### 6.4 유지보수성 (Maintainability)
- 명확한 코드 주석 및 문서화
- 단위 테스트 작성 (Google Test)
- 로깅 시스템 구현

---

## 7. 테스트 요구사항

### 7.1 단위 테스트 (Unit Testing)
- Google Test 프레임워크 사용
- 각 모듈별 테스트 케이스 작성
- 최소 80% 코드 커버리지

### 7.2 통합 테스트 (Integration Testing)
- Client-Server 통신 테스트
- RTSP 비디오 스트리밍 테스트
- 에러 시나리오 테스트

### 7.3 시스템 테스트 (System Testing)
- 전체 시스템 통합 테스트
- 성능 테스트 (지연, 프레임 레이트)
- 안정성 테스트 (장시간 운영)

---

## 8. 배포 및 설치

### 8.1 Docker 컨테이너
- Client 및 Server 각각 Docker Image 생성
- `docker-compose.yml` 제공 (선택 사항)

### 8.2 설치 절차
1. 저장소 클론
2. 의존성 설치 (vcpkg)
3. CMake 빌드
4. Docker Image 빌드
5. 컨테이너 실행

---

## 9. 마일스톤 (Milestones)

| Phase | 목표 | 기한 |
|-------|------|------|
| Phase 1 | 기본 Client-Server 통신 구현 | - |
| Phase 2 | RTSP/H.264 비디오 스트리밍 구현 | - |
| Phase 3 | Qt UI 개발 | - |
| Phase 4 | 화면 제어 기능 구현 | - |
| Phase 5 | 테스트 및 최적화 | - |
| Phase 6 | Docker 배포 준비 | - |

---

## 10. 참고사항

- 모든 코드는 CMake로 빌드 가능해야 함
- 크로스 플랫폼 호환성 고려 (Ubuntu/WSL2)
- 보안 고려사항 필요 (네트워크 통신 암호화 검토)
- 정기적인 코드 리뷰 및 테스트 수행

---

**문서 작성일**: 2026-07-07  
**버전**: 1.0
