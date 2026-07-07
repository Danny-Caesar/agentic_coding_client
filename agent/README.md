# Agent Directory

이 디렉토리는 프로젝트에서 사용할 에이전트 관련 스킬, 스크립트, 참조 정의를 포함합니다.

구성:
- `skills/` - 에이전트가 사용할 마크다운 형식의 스킬 파일
- `scripts/` - 환경 설정 및 설치를 자동화하는 셸 스크립트
- `reference/` - 참조용 에이전트 템플릿 및 사용 예시

간단 사용 예:
```bash
# 베이스 환경 설치
bash agent/scripts/setup_env.sh

# vcpkg 설치 (sudo 필요)
sudo bash agent/scripts/setup_vcpkg.sh
```
