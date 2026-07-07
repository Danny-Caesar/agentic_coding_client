# Sprint 1 Backlog

- 스프린트: Sprint 1
- 기간: 2026-07-08 ~ 2026-07-21
- 목표: 기본 클라이언트-서버 통신과 RTSP 스트림 재생 환경 구성

## 커밋된 스토리

- PB-101: 클라이언트가 H.264 RTSP 스트림을 수신·표시 (8 SP) — Status: Done
- PB-201: Frame Rate/Resolution 원격 제어 구현 (5 SP) — Status: Done
- PB-501: vcpkg 및 Docker를 사용한 개발환경 문서화 및 기본 스크립트 제공 (5 SP) — Status: Done

## 작업 항목
- `agent/scripts/setup_env.sh` 점검 및 개선 — 완료
- `agent/scripts/setup_vcpkg.sh` 실행 검증 — 완료
- `CMakeLists.txt` 기본 템플릿 작성 — 완료 (템플릿 위치: project root)
- 간단한 RTSP 수신 예제 (OpenCV/FFmpeg) 작성 — 완료 (예제 경로: examples/rtsp_demo.cpp)

## 산출물(artifacts)
- artifacts/sprint-1/pb-101-unit.log
- artifacts/sprint-1/pb-201-unit.log
- artifacts/sprint-1/pb-501-install.log

## 회고
- 잘된 점: 기본적인 스트리밍 파이프라인과 개발 환경 자동화 스크립트 구축
- 개선할 점: RTSP 에러 처리 루틴과 자동 재연결 강화
