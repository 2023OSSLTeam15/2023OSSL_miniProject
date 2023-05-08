# 한동대학교 학생들의 교회 출석 현황을 확인할 수 있는 어플

![image](https://user-images.githubusercontent.com/130723603/236840361-b502ef0d-a3c9-404d-9c91-e9087c930d00.png)

- 우리 학교 학생들은 매주 어떤 교회에 가는 걸까? 그 궁금증을 해결해 드리기 위한 프로그램을 제작했습니다.
한동대학교 구성원이라면 누구나 이 프로그램을 통해서 본인이 매주 방문하는 교회에 대한 정보(교회 이름, 교회 주소, 청년부 예배 시작 시간, 매주/매달 방문자 수 등)를 한동대학교 모두와 공유할 수 있습니다.
- 정해둔 외부 교회가 없어서 매주 고민하시는 분들 혹은 이번 주 내게 새로운 변화가 필요하다고 생각하시는 분들을 위한 무작위 교회 추천 게임이 포함되어 있습니다.

project 에 포함시킬 기능 설명
- 메뉴 출력 (int): 이 프로그램을 작동하기 위한 메뉴를 출력하고 그 값을 반환합니다.
- 목록 조회 (void): 교회 정보 리스트를 출력합니다.
- 목록 추가 (void): 교회 정보 리스트에 교회 정보를 추가합니다.
- 목록 수정 (void): 교회 정보 중 잘못되었거나 변경된 항목이 있다면 수정합니다.
- 목록 삭제 (void): 교회 정보를 삭제합니다.
- 출석 기록 저장 (void): 교회 이름이 입력되면 해당되는 교회의 이번주 출석자 수를 1만큼 더합니다. 일요일 여부 확인 함수를 호출한 후 만약 반환값이 true일 때 이 함수를 실행합니다. 반환값이 false라면 함수를 실행하지 않고 오류 메세지를 출력합니다.
- 이번 주 교회 출석 현황 조회 (void): 해당 주차에 대한 교회 정보를 출석자가 많은 순서대로 정렬해서 나타냅니다.
- 이번 달 교회 출석 현황 조회 (void): 해당 주차에 대한 교회 정보를 출석자가 많은 순서대로 정렬해서 나타냅니다.
- 데이터 저장 (void): 메뉴가 실행된 시점의 리스트 데이터를 저장합니다.
- 데이터 로드 (void): 리스트 데이터를 불러와 현재 프로그램에 적용시킵니다.
- 일요일 여부 확인 (bool): 현재 요일을 확인하고 만약 일요일이라면 true, 아니라면 false를 반환합니다.
- 오늘의 교회 추천 (void): 랜덤으로 교회를 뽑아 멘트와 함께 출력합니다.

개발환경 및 언어
- 
팀소개 및 팀원이 맡은 역할
