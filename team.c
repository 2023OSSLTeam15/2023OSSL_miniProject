#include "team.h"

int selectMenu(){
    int menu;
    printf("\n*** 한동 교회 출석 현황 ***\n");
    printf("1. 목록 조회\n");
    printf("2. 목록 추가\n");
    printf("3. 목록 수정\n");
    printf("4. 목록 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 교회 검색\n");
    printf("7. 이번 주 교회 출석 현황\n");
    printf("6. 이번 달 교회 출석 현황\n");
    printf("6. 오늘의 추천 교회는?\n");
    printf("0. 종료\n\n");
    printf(">> 원하는 메뉴를 골라주세요:  ");
    scanf("%d", &menu);
    return menu;
}