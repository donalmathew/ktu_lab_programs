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

void main(){
    int nb,b,current,f=0,flag=0;
    printf("Enter the total no. of blocks in the disk: ");
    scanf("%d",&nb);
    struct Block *block[nb];
    struct File file[MAXSIZE];
    for(int i=0;i<nb;i++){
        block[i]=(struct Block *)malloc(sizeof(struct Block));
        block[i]->allocated=0;
        block[i]->num=i;
    }

    do{
        printf("Enter the id of the file: ");
        scanf("%d",&file[f].id);
        while(true){
            printf("Enter the starting block: ");
            scanf("%d",&file[f].st);
            if(block[file[f].st]->allocated==0){
                block[file[f].st]->allocated=1;
                break;
            } else{
                printf("Block already allocated. Enter another block.\n");
            }
        }
        while(true){
            printf("Enter the ending block: ");
            scanf("%d",&file[f].end);
            if(block[file[f].end]->allocated==0){
                block[file[f].end]->allocated=1;
                break;
            } else{
                printf("Block already allocated. Enter another block.\n");
            }
        }
        
        current=file[f].st;
        block[current]->next=NULL;
        
        printf("Enter the length of the file: ");
        scanf("%d",&file[f].len);
        printf("Enter the other blocks to be allocated: ");
        for(int i=0;i<(file[f].len-2);i++){
            scanf("%d",&b);
            if(block[b]->allocated==0){
                block[current]->next=block[b];
                block[b]->allocated=1;
                current=b;
            } else {
                printf("Block already allocated. Enter another block\n");
                i--;
            }
        }
        block[current]->next=block[file[f].end];
        block[file[f].end]=NULL;
        f++;
        printf("File allocated\n");
        printf("Do you want to allocate more files?(Y=1,N=0): ");
        scanf("%d",&flag);

    }while(flag==1);

    printf("FILE ALLOCATION\n\n");
    for(int i=0;i<f;i++){
        printf("File %d\n",file[i].id);
        current=file[i].st;
        for(int j=0;j<file[i].len-1;j++){
            printf("%d->",current);
            current=block[current]->next->num;
        }
        printf("%d\n",file[i].end);
    }
    printf("\n");
}