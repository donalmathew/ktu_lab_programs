#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 50

struct Block {
    int num;
    int allocated;
    struct Block *next;
};
struct File {
    int id;
    int st,len,end;
};


