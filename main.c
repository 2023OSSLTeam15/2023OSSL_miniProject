#include "team.h"

#define MAX 50

int main(void){
    Church *c[MAX];
    int count=0, index=0, menu;
    
    count = loadBoard(c);
    index = count;

    while (1){
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
        }
        else if (menu == 3){
            int no = selectDataNo(c, index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateBoard(c[no-1]);
        }
        else if (menu == 4){
            deleteBoard(c, count);
        }
        else if (menu == 5){
            saveBoard(c, count);
        }
        else if (menu == 6){
            searchBoard(c, index);
        }
        else if (menu == 7){}
        else if (menu == 8){}
        else if (menu == 9){}
        else if (menu == 10){
            attendance(c, count);
        }
    }
    
    printf("이용해 주셔서 감사합니다. 좋은 하루 되세요!\n");
    return 0;
}

