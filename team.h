#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 100

typedef struct{
    char name[50];
    char adress[50];
    char time[4];

    int count;
    int isSun;
}Church;

int selectMenu();

int addBoard(Church *c);
void readBoard(Church *c[], int count);
int updateBoard(Church *c);
int deleteBoard(Church *c);
void searchBoard(Church *c[], int count);

void saveBoard(Church *c[], int count);
int loadBoard(Church *c[]);

int attendance();
void thisWeek();
void thisMonth();
int isSunday();
void recommendCurch(Church *c[], int count);