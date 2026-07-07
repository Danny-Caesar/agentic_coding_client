# Reference Agent

이 파일은 다른 에이전트들이 참조할 수 있는 예시 에이전트 정의와 사용 예시를 제공합니다.

## 예시: dev-agent

```
name: dev-agent
description: 개발 업무를 자동화하는 에이전트 예시
type: agent
applyTo:
 - "src/**"
 - "tests/**"

responsibilities:
 - 코드 생성 및 포맷
 - 단위 테스트 작성
 - PR 요약 생성

usage:
 - dev-agent는 특정 파일/폴더를 대상으로 자동 코드 업데이트를 수행할 수 있습니다.
```

## 스크립트 호출 예시

`setup-manager`는 아래와 같이 `setup_env.sh`와 `setup_vcpkg.sh`를 호출합니다:

```bash
bash agent/scripts/setup_env.sh
sudo bash agent/scripts/setup_vcpkg.sh
```
