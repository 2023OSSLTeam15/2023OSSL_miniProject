#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct church{
    char name[50];
    char adress[50];
    char time[4];

    int count;
} Score;

int main(void){
    int menu;

    while (1){
        menu = selectMenu();
        if (menu == 0){
            printf("변경 내용 저장 후 프로그램이 종료됩니다.\n");
            printf("정말 종료하시겠습니까?\n");
            // 조건문으로 종료 처리
        }
        if (menu == 1){

        }
        else if (menu == 2){

        }
        else if (menu == 3){
            
        }
        else if (menu == 4){
            
        }
        else if (menu == 5){
            
        }
        else if (menu == 6){
            
        }
    }
    
    printf("이용해 주셔서 감사합니다. 좋은 하루 되세요!");
    return 0;
}

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