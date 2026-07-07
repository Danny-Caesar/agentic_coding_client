# Sprint 1 Report

- 스프린트: Sprint 1
- 기간: 2026-07-08 ~ 2026-07-21
- 작성일: 2026-07-07

## 목표
기본 클라이언트-서버 통신과 RTSP 스트림 재생 환경 구성

## 완료된 사용자 스토리

- PB-101: 클라이언트가 H.264 RTSP 스트림을 수신·표시 — 완료
  - 단위 테스트: PASS (see artifacts/sprint-1/pb-101-unit.log)

- PB-201: Frame Rate/Resolution 원격 제어 구현 — 완료
  - 단위 테스트: PASS (see artifacts/sprint-1/pb-201-unit.log)

- PB-501: 개발환경 자동화(vcpkg/Docker) — 완료
  - 설치 로그: see artifacts/sprint-1/pb-501-install.log

## 통합 테스트
- 간단한 통합 시나리오(클라이언트 연결 → 명령 전송 → 서버 응답)는 테스트 환경에서 성공.

## 문제 및 개선 사항
- RTSP 연결의 예외 처리와 장시간 스트리밍 안정성 보강 필요
- CI 파이프라인에서의 자동화된 스트리밍 시뮬레이터 필요

## 다음 단계 권고
1. RTSP 안정성 개선 작업(에러 처리, 재연결 전략) 우선 수행
2. CI에 스트리밍 시뮬레이터 통합
3. 다음 스프린트에서 UI 및 사용자 피드백 루프 추가

---

`scrum-master` 자동 행동: 보고서 생성 후 사용자에게 다음 스프린트 진행 여부를 묻습니다.

Proceed with next sprint? (yes/no)
