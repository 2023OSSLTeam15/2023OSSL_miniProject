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
    //printf("7. 이번 주 교회 출석 현황\n");
    //printf("8. 이번 달 교회 출석 현황\n");
    //printf("9. 오늘의 추천 교회는?\n");
    printf("0. 종료\n\n");
    printf(">> 원하는 메뉴를 골라주세요:  ");
    scanf("%d", &menu);
    return menu;
}

int addBoard(Church *c){
    printf("교회 이름은?  ");
    scanf("%s", c->name);
    printf("교회 주소는?  ");
    scanf("%s", c->address);
    printf("청년부 예배 시간은(00:00 형태로 표기)?  ");
    scanf("%s", c->time);
    printf("=> 추가됨!\n\n");
    return 1;
}

void listBoard(Church *c[], int count){
    printf("\nNo   Name   Address \t time\n");
    printf("=====================================\n);
    for(int i=0; i<count; i++){
        if(c[i]==NULL) continue;
        printf("%2d ", i+1);
        readBoard(*c[i]);
    }
    printf("\n");
}

void readBoard(Church c){
    printf(" %s  %s \t %s\n", c.name, c.address, c.time);
}

int selectDataNo(Church *c[], int count){
    int no;
    listBoard(c, count);
    printf("번호는 (취소: 0)? ");
    scanf("%d", &no);
    return no;
}

int updateBoard(Church *c){
    printf("교회 이름은?  ");
    scanf("%s", c->name);
    printf("교회 주소는?  ");
    scanf("%s", c->address);
    printf("청년부 예배 시간은(00:00 형태로 표기)?  ");
    scanf("%s", c->time);
    printf("=> 수정됨!\n");
    return 1;
}

int deleteBoard(Church *c){}

void searchBoard(Church **c, int count){
    int scnt = 0;
    char search[50];
    
    printf("검색할 교회 이름?  ");
    scanf("%s", search);
    
    printf("\nNo   Name   Address \t time\n");
    printf("=====================================\n);
    for(int i=0; i<count; i++){
        if(c[i] == NULL) continue;
        if(strstr(c[i]->name, search)){
            printf("%2d ", i+1);
            readBoard(*c[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}



void saveBoard(Church **c, int count){}

int loadBoard(Church **c){}



int attendance(){}

void thisWeek(){}

void thisMonth(){}

int isSunday(){}

void recommendChurch(Church *c[], int count){}
