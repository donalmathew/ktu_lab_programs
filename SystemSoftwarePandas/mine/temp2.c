#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct File{
	char filename[20];
	int startblock;
	int len;
};
typedef struct File File;

struct Directory{
	File files[100];
	int fileCount;
};
typedef struct Directory Directory;
int blocks[32]={0};

void main(){
	Directory dir;
	dir.fileCount=0;

	int choice,flag=0;
	do{
		printf("\n1.add file");
		printf("\n2.display directory");
		printf("\n3.Delete file");
		printf("\n4.exit");
		printf("\nenter your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				if(dir.fileCount >= 100){
					print("\nDirectory is full. Cannot add more files");
					break;
				}

				char filename[20];
				int startBlock,len,count=0;
				printf("\nenter filename:");
				scanf("%s",filename);

				for(int i=0;i<dir.fileCount;i++){
					if(!strcmp(filename,dir.files[i].filename)){
						printf("File already exists!\n);





