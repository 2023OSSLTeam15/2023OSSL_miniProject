#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct{
    char name[50];
    char address[50];
    char time[10];
    int att;
}Church;

typedef struct{
    Church *churches[MAX];
    int date[3];
    int Ccount;
}History;

int selectMenu();

int addBoard(Church *c);    //Create
void listBoard(Church *c[], int count); //Read
void readBoard(Church c);
int selectDataNo(Church *c[], int count);   //Selecting number (for Update, Delete)
int updateBoard(Church *c); //Update
void deleteBoard(Church **c, int count); //Delete
void searchBoard(Church **c, int count);

void saveBoard(Church *c[], int count);
int loadBoard(Church *c[]);

int attendance(Church *c[], int count);
void thisWeek(History *h[], int Hcount);
void thisMonth(History *h[], int Hcount);
int isSunday();
void recommendChurch(Church *c[], int count);

int weeklyRecord(Church *c[], int count, History *h[], int Hcount, int year, int month, int day);
int loadWBoard(History *h[]);