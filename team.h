#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 100

typedef struct{
    char name[50];
    char address[50];
    char time[10];

    int count;
    int isSun;
} Church;

int selectMenu();

int addBoard(Church *c);    //Create
void listBoard(Church *c[], int count); //Read
void readBoard(Church c);
int selectDataNo(Church *c[], int count);   //Selecting number (for Update, Delete)
int updateBoard(Church *c); //Update
int deleteBoard(Church *c); //Delete
void searchBoard(Church **c, int count);

void saveBoard(Church **c, int count);
int loadBoard(Church **c);

int attendance();
void thisWeek();
void thisMonth();
int isSunday();
void recommendChurch(Church *c[], int count);
