#include "team.h"

int selectMenu(){
    int menu;
    printf("\n*** 한동 교회 출석 현황 ***\n");
    printf("1. 목록 조회\n");
    printf("2. 목록 추가\n");
    printf("3. 목록 수정\n");
    printf("4. 목록 삭제\n");
    printf("5. 목록 저장\n");
    printf("6. 목록 검색\n");
    printf("7. 최근 교회 출석 현황\n");
    printf("8. 최근 4주 교회 출석 현황\n");
    printf("9. 오늘의 추천 교회는? 랜덤 게임!\n");
    printf("10. 출석 체크\n");
    printf("0. 프로그램 종료\n\n");
    printf(">> 원하는 메뉴를 골라주세요:  ");
    scanf("%d", &menu);
    return menu;
}

int addBoard(Church *c){
    getchar();
    printf("교회 이름: ");
    fgets(c->name, sizeof(c->name), stdin);
    c->name[strlen(c->name) - 1] = '\0';
    printf("교회 주소: ");
    fgets(c->address, sizeof(c->address), stdin);
    c->address[strlen(c->address) - 1] = '\0';
    printf("청년부 예배 시간(ex. 00:00): ");
    fgets(c->time, sizeof(c->time), stdin);
    c->time[strlen(c->time) - 1] = '\0';
    c->att = 0;
    printf(">> 추가되었습니다!\n\n");
}

void listBoard(Church *c[], int count){
    printf("\nNo Name\t\t\tAddress\t\t\ttime\tattendance\n");
    printf("===================================================================\n");
    for(int i = 0; i < count; i++){
        if(c[i]->att == -1) continue;
        printf("%2d ", i+1);
        readBoard(*c[i]);
    }
    printf("\n");
}

void readBoard(Church c){
    printf(" %s\t%s\t%s\t%d\n", c.name, c.address, c.time, c.att);
}

int selectDataNo(Church *c[], int count){
    int no;
    listBoard(c, count);
    printf("번호(취소: 0): ");
    scanf("%d", &no);
    return no;
}

int updateBoard(Church *c){
    getchar();
    printf("교회 이름: ");
    fgets(c->name, sizeof(c->name), stdin);
    c->name[strlen(c->name) - 1] = '\0';
    printf("교회 주소: ");
    fgets(c->address, sizeof(c->address), stdin);
    c->address[strlen(c->address) - 1] = '\0';
    printf("청년부 예배 시간(ex. 00:00): ");
    fgets(c->time, sizeof(c->time), stdin);
    c->time[strlen(c->time) - 1] = '\0';
    printf(">> 수정 완료!\n");
    return 1;
}

void deleteBoard(Church **c, int count){
    int number, aNumber;

    listBoard(c, count);
    printf("삭제할 리스트의 번호를 알려주세요. (취소: 0):  ");
    scanf("%d", &number);

    if (number == 0){
        return;
    }
    else{
        printf("정말로 삭제하시겠습니까? (삭제: 1 | 취소: 0):  ");
        scanf("%d", &aNumber);

        if (aNumber==1){
            c[number - 1]->att = -1;
            strcpy(c[number - 1]->name, "");
            printf(">> 삭제되었습니다!\n");
        }
        else{
            return;
        }
    }
}

void searchBoard(Church **c, int count){
    int scnt = 0;
    char search[50];

    getchar();
    printf("검색할 교회 이름:  ");
    fgets(search, sizeof(search), stdin);
    search[strlen(search) - 1] = '\0';
    
    printf("\nNo Name\t\t\tAddress\t\t\ttime\tattendance\n");
    printf("===================================================================\n");
    for(int i=0; i<count; i++){
        if(c[i]->att == -1) continue;
        if(strstr(c[i]->name, search)){            
            printf("%2d ", i+1);
            readBoard(*c[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf(">> 검색된 데이터 없음!");
    printf("\n");
}

void saveBoard(Church *c[], int count){
    FILE *fp;

    fp = fopen("church.txt", "w+");

    for (int i=0; i<count; i++){
        if (c[i]->att == -1){
            continue;
        }
        else{
            fprintf(fp, "%s\t%s\t%s\t%d\n", c[i]->name, c[i]->address, c[i]->time, c[i]->att);
        }
    }
    fclose(fp);
    printf(">> 저장 완료!\n");  }

int loadBoard(Church *c[]){
    FILE *fp;
    char input[100];
    char *split;
    int count = 0;
    fp = fopen("church.txt", "r");

    if (fp == NULL){
        printf("아직 저장된 파일이 없습니다. (1)\n");
    }
    else{
        while(fgets(input, 100, fp) != NULL){
            c[count] = (Church*)malloc(sizeof(Church));

            split = strtok(input, "\t");
            strcpy(c[count]->name, split);
            split = strtok(NULL, "\t");
            strcpy(c[count]->address, split);
            split = strtok(NULL, "\t");
            strcpy(c[count]->time, split);
            split = strtok(NULL, "\t");
            c[count]->att = atoi(split);
            
            if(feof(fp))
                break;

            count++;
        }
        printf("저장된 파일을 불러왔습니다. (1)\n");
        return count;
    }
}

int attendance(Church *c[], int count){
    int ss = isSunday();
    if (ss == 1){
        int number, aNumber;
        time_t now;
        struct tm *tm_now; // 변환된 시간 정보를 저장할 구조체

        time(&now);// 현재 시간 구하기
        tm_now = localtime(&now);// 현재 시간 정보 구조체로 변환

        listBoard(c, count);
        printf("출석 체크할 교회의 번호를 입력해 주세요. (취소: 0) ");
        scanf("%d", &number);

        if (number == 0){
            return 0;
        }
        else{
            printf("정말로 이 교회가 맞나요? (확인: 1 | 취소: 0)");
            scanf("%d", &aNumber);

            if (aNumber==1){
                c[number - 1]->att++;
            }
            else{
                return 1;
            }
        }
    }
    else{
        return -1;
    }
}

void thisWeek(History *h[], int Hcount){
    if (Hcount == 0){
        printf("아직 아무도 출석 체크를 진행하지 않았습니다.\n다가오는 일요일, 처음으로 출석 체크를 시도해 보세요!\n");
    }
    else{
        printf("*** 최근 교회 출석 현황 ***\n");

        listBoard(h[Hcount - 1]->churches,  h[Hcount - 1]->Ccount);
    }
}

void thisMonth(History *h[], int Hcount){
    if (Hcount == 0){
        printf("아직 아무도 출석 체크를 진행하지 않았습니다.\n다가오는 일요일, 처음으로 출석 체크를 시도해 보세요!\n");
    }
    else{
        int four = Hcount - 4; // 만약 프로그램이 4주 미만의 데이터를 가지고 있을 때 사용할 변수

        printf("*** 최근 4주 교회 출석 현황 ***\n");
        printf("** 가장 최근 주부터 출력됩니다! **\n");

        if (four < 0){
            for (int i = 1; i <= 4 + four; i++){
                printf("* %d *\n", i);
                listBoard(h[Hcount - i]->churches,  h[Hcount - i]->Ccount);
            }
        }
        else{
            for (int i = 1; i <= 4; i++){
                printf("* %d *\n", i);
                listBoard(h[Hcount - i]->churches,  h[Hcount - 1]->Ccount);
            }
        }
    }
}

int isSunday(){
    time_t now;
    struct tm *tm_now; // 변환된 시간 정보를 저장할 구조체

    time(&now);// 현재 시간 구하기
    tm_now = localtime(&now);// 현재 시간 정보 구조체로 변환

    printf("[%d년 %d월 %d일 %d시 %d분]\n",
            tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday,
            tm_now->tm_hour, tm_now->tm_min);

    if (tm_now->tm_wday == 0) {
      printf("오늘은 일요일입니다. 행복한 주일 되세요!\n");
      return 1;
    }
    else {
      printf("오늘은 일요일이 아닙니다.\n이 메뉴는 일요일에만 활성화됩니다.\n감사합니다.\n");
      return 0;
    }
}

void recommendChurch(Church *c[], int count){
    int num;

    srand(time(NULL)); // 현재 시간을 시드값으로 사용하여 랜덤 시퀀스 초기화
    num = rand() % count; // 0부터 count-1까지의 난수 생성
    printf("오늘의 추천 교회는? (두구두구~)");
    printf("*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n");
    printf("[ %s ]입니다! 알찬 주일 보내시길 바랍니다!\n", c[num]->name);
}

int weeklyRecord(Church *c[], int count, History *h[], int Hcount, int year, int month, int day) {
    FILE *fp;
    int Cnum = 0;

    time_t now;
    struct tm *tm_now; // 변환된 시간 정보를 저장할 구조체

    time(&now);// 현재 시간 구하기
    tm_now = localtime(&now);// 현재 시간 정보 구조체로 변환

    if (Hcount == 0){
        h[Hcount] = (History *)malloc(sizeof(History));
        Cnum = 0;
        for (int i = 0; i < count; i++){
            h[Hcount]->churches[i] = (Church *)malloc(sizeof(Church));

            strcpy(h[Hcount]->churches[i]->name, c[i]->name);
            strcpy(h[Hcount]->churches[i]->address, c[i]->address);
            strcpy(h[Hcount]->churches[i]->time, c[i]->time);
            h[Hcount]->churches[i]->att = c[i]->att;

            Cnum++;
        }
        h[Hcount]->Ccount = Cnum;
        h[Hcount]->date[0] = year;
        h[Hcount]->date[1] = month;
        h[Hcount]->date[2] = day;

        char filename[10];
        sprintf(filename, "week%d.txt", Hcount+1);

        fp = fopen(filename, "w+");
        
        for (int i = 0; i < Cnum; i++){
            fprintf(fp, "%s\t%s\t%s\t%d\n", h[Hcount]->churches[i]->name, h[Hcount]->churches[i]->address, h[Hcount]->churches[i]->time, h[Hcount]->churches[i]->att); 
        }
        fclose(fp);

        printf(">> 저장 완료!\n");
        Hcount++;
    }
    else{
        if (year == h[Hcount-1]->date[0] && month == h[Hcount-1]->date[1] && day == h[Hcount-1]->date[2]){
            printf("날짜 동일\n");
            Cnum = 0;
            for (int i = 0; i < count; i++){

                strcpy(h[Hcount-1]->churches[i]->name, c[i]->name);
                strcpy(h[Hcount-1]->churches[i]->address, c[i]->address);
                strcpy(h[Hcount-1]->churches[i]->time, c[i]->time);
                h[Hcount-1]->churches[i]->att = c[i]->att;

                Cnum++;
            }

            char filename[10];
            sprintf(filename, "week%d.txt", Hcount);

            fp = fopen(filename, "w+");
        
            for (int i = 0; i < Cnum; i++){
                fprintf(fp, "%s\t%s\t%s\t%d\n", h[Hcount-1]->churches[i]->name, h[Hcount-1]->churches[i]->address, h[Hcount-1]->churches[i]->time, h[Hcount-1]->churches[i]->att); 
            }
            fclose(fp);

            printf(">> 저장 완료!\n");
            h[Hcount-1]->Ccount = Cnum;
        }
        else{
            h[Hcount] = (History *)malloc(sizeof(History));
            Cnum = 0;
            for (int i = 0; i < count; i++){
                h[Hcount]->churches[i] = (Church *)malloc(sizeof(Church));

                strcpy(h[Hcount]->churches[i]->name, c[i]->name);
                strcpy(h[Hcount]->churches[i]->address, c[i]->address);
                strcpy(h[Hcount]->churches[i]->time, c[i]->time);
                h[Hcount]->churches[i]->att = c[i]->att;

                Cnum++;
            }
            h[Hcount]->date[0] = tm_now->tm_year + 1900;
            h[Hcount]->date[1] = tm_now->tm_mon + 1;
            h[Hcount]->date[2] = tm_now->tm_mday;

            char filename[10];
            sprintf(filename, "week%d.txt", Hcount+1);

            fp = fopen(filename, "w+");
        
            for (int i = 0; i < Cnum; i++){
                fprintf(fp, "%s\t%s\t%s\t%d\n", h[Hcount]->churches[i]->name, h[Hcount]->churches[i]->address, h[Hcount]->churches[i]->time, h[Hcount]->churches[i]->att); 
            }
            fclose(fp);

            printf(">> 저장 완료!\n");
            h[Hcount]->Ccount = Cnum;
            Hcount++;
        }
    }
    return Hcount;
}

int loadWBoard(History *h[]){
    FILE *fp;
    char filename[10];
    char input[100];
    char *split;
    int count = 0;
    int hcount = 0;

    for (int i = 0; i < 4; i++){
        count = 0;
        sprintf(filename, "week%d.txt", i+1);

        fp = fopen(filename, "r");

        if (fp == NULL){
            fclose(fp);
            return i;
        }
        else{
            h[i] = (History *)malloc(sizeof(History));
            while(fgets(input, 100, fp) != NULL){
                h[i]->churches[count] = (Church*)malloc(sizeof(Church));

                split = strtok(input, "\t");
                strcpy(h[i]->churches[count]->name, split);
                split = strtok(NULL, "\t");
                strcpy(h[i]->churches[count]->address, split);
                split = strtok(NULL, "\t");
                strcpy(h[i]->churches[count]->time, split);
                split = strtok(NULL, "\t");
                h[i]->churches[count]->att = atoi(split);
            
                if(feof(fp))
                    break;

                count++;
            }            
            fclose(fp);
            printf("저장된 파일을 불러왔습니다. (%d)\n", i+2);
            h[i]->Ccount = count;
        }
        hcount++;

    }
    return hcount;
}