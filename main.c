#include "team.h"

int main(void){
    time_t now;
    struct tm *tm_now; // 변환된 시간 정보를 저장할 구조체

    time(&now);// 현재 시간 구하기
    tm_now = localtime(&now);// 현재 시간 정보 구조체로 변환

    Church *c[MAX];
    History *h[4]; //4주의 기록만 저장함
    int Hcount = 0; 
    int count = 0;
    
    int menu;

    count = loadBoard(c);
    Hcount = loadWBoard(h);

    while (1){
        menu = selectMenu();
        if (menu == 0){
            int exitok;

            printf("변경 내용 저장 후 프로그램이 종료됩니다.\n");
            printf("정말 종료하시겠습니까?(종료: 1): ");
            scanf("%d", &exitok);
            
            if(exitok == 1){
                saveBoard(c, count);
                printf("프로그램을 종료합니다!\n");
                break;
            }
            else{
                printf("프로그램 종료가 취소되었습니다!\n");
                continue;
            }
        }
        if (menu == 1){
            listBoard(c, count);
        }
        else if (menu == 2){
            c[count] = (Church *)malloc(sizeof(Church));
            addBoard(c[count]);
            count ++;

        }
        else if (menu == 3){
            int no = selectDataNo(c, count);
            if(no == 0){
                printf(">> 취소됨!\n");
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
            searchBoard(c, count);
        }
        else if (menu == 7){
            printf("%d\n", Hcount);
            thisWeek(h, Hcount);
        }
        else if (menu == 8){
            printf("%d\n", Hcount);
            thisMonth(h, Hcount);
        }
        else if (menu == 9){
            recommendChurch(c, count);
        }
        else if (menu == 10){
            if (attendance(c, count) == -1){
                continue;
            }
            Hcount = weeklyRecord(c, count, h, Hcount, tm_now->tm_year, tm_now->tm_mon, tm_now->tm_mday);
        }
    }
}