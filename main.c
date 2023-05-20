#include "team.h"

int main(void){
    Church *c[MAX];
    History h[MAX];
    int count = 0, *Hcount = 0; 
    int index = 0;
    int menu;
    
    count = loadBoard(c);
    if (count == -1){
        printf(">> 저장된 파일이 없습니다. 지금부터 기록을 시작합니다.\n");
    }
    else{
        printf(">> 로딩에 성공했습니다! 이어서 기록을 시작합니다.");
    }
    index = count;

    while (1){
        count = loadBoard(c);
        menu = selectMenu();
        if (menu == 0){
            int exitok;
            printf("변경 내용 저장 후 프로그램이 종료됩니다.\n");
            printf("정말 종료하시겠습니까?(종료: 1)\n");
            // 조건문으로 종료 처리
            scanf("%d", &exitok);
            if(exitok==1){
                printf("프로그램을 종료합니다!\n");
                break;
            }
            else{
                printf("프로그램 종료가 취소되었습니다!\n");
                continue;
            }
        }
        if (menu == 1){
            listBoard(c, index);
        }
        else if (menu == 2){
            c[index] = (Church *)malloc(sizeof(Church));
            count += addBoard(c[index++]);
            saveBoard(c, count);
        }
        else if (menu == 3){
            int no = selectDataNo(c, index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateBoard(c[no-1]);
            saveBoard(c, count);
        }
        else if (menu == 4){
            deleteBoard(c, count);
            saveBoard(c, count);
        }
        else if (menu == 5){
            saveBoard(c, count);
        }
        else if (menu == 6){
            searchBoard(c, index);
        }
        else if (menu == 7){
            thisWeek(c, h, count, Hcount);
        }
        else if (menu == 8){
            thisMonth(c, h, count, Hcount);
        }
        else if (menu == 9){
            recommendChurch(c, count);
        }
        else if (menu == 10){
            attendance(c, count);
        }
    }
    
    printf("이용해 주셔서 감사합니다. 좋은 하루 되세요!\n");
    return 0;
}

