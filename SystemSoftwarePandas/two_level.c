#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define MAX_FILES 100
#define MAX_FILENAME 20
#define MAX_BLOCKS 32

struct File {
    char filename[MAX_FILENAME];
    int startBlock;
    int len;
};

typedef struct File File;

struct Directory {
    char dname[MAX_FILENAME];
    File files[MAX_FILES];
    int fileCount;
};

typedef struct Directory Directory;
int blocks[MAX_BLOCKS]={0};

void main() {
    Directory dir[10];
    int dcnt=0;
    char f[30],d[30];

    int choice,flag=0;
    do {
        printf("\n--- Two-Level Directory File Organization ---\n");
        printf("1. Create directory\n");
        printf("2. Add File\n");
        printf("3. Display Directory\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter directory name: ");
                scanf("%s",d);
                for(int i=0;i<dcnt;i++){
                    if(!strcmp(d,dir[i].dname)){
                        printf("Directory already exists!\n");
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    strcpy(dir[dcnt].dname,d);
                    dir[dcnt].fileCount=0;
                    printf("Directory '%s' created\n",dir[dcnt].dname);
                    dcnt++;
                }
                break;

            case 2:
                printf("Enter directory name: ");
                scanf("%s",d);
                int found=0;
                flag=0;
                for(int i=0;i<dcnt;i++){
                    if(!strcmp(d,dir[i].dname)){
                        found=1;
                        if (dir[i].fileCount >= MAX_FILES) {
                            printf("Directory is full. Cannot add more files.\n");
                            break;
                        }
            
                        char filename[MAX_FILENAME];
                        int startBlock, len, count=0;
                        printf("Enter filename: ");
                        scanf("%s", filename);
                        for(int j=0;j<dir[i].fileCount;j++){
                            if(!strcmp(filename,dir[i].files[j].filename)){
                                printf("File already exists!\n");
                                flag=1;
                                break;
                            }
                        }
                        while(flag==0){
                            printf("Enter starting block for the file: ");
                            scanf("%d", &startBlock);
                            printf("Enter length of the file: ");
                            scanf("%d", &len);
                            for(int j=startBlock;j<(startBlock+(len));j++){
                                //printf("Hi\n");
                                if(blocks[j]==0){
                                    count++;
                                }
                            }

                            if(len==count){
                                for(int j=startBlock;j<(startBlock+len);j++){
                                    
                                    if(blocks[j]==0){
                                        
                                        blocks[j]=1;
                                    }
                                }
                                break;
                            } else {
                                printf("Blocks already allocated. Enter another block\n");
                            }
                        }

                        if (dir[i].fileCount < MAX_FILES && flag==0) {
                            strcpy(dir[i].files[dir[i].fileCount].filename, filename);
                            dir[i].files[dir[i].fileCount].startBlock = startBlock;
                            dir[i].files[dir[i].fileCount].len = len;
                            
                            dir[i].fileCount++;
                            printf("File '%s' added to the directory.\n", filename);
                        } else {
                            printf("Directory is full. Cannot add more files.\n");
                        }
                    }
                }
                if(found==0){
                    printf("Directory not found!\n");
                }
                break;

            case 3:
                printf("Directory Structure:\n");
                printf("Root\n");

                for(int i=0;i<dcnt;i++){
                    printf("|-- %s\n",dir[i].dname);
                    for (int j = 0; j < dir[i].fileCount; j++) {
                        printf("|   |-- %s | start block: %d | end block: %d |\n",
                            dir[i].files[j].filename, dir[i].files[j].startBlock, (dir[i].files[j].startBlock+dir[i].files[j].len));
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Enter directory name: ");
                scanf("%s",d);
                int found_dir=0,found_file=0;
                for(int i=0;i<dcnt;i++){
                    if(!strcmp(d,dir[i].dname)){
                        found_dir=1;
                        printf("Enter the file name to be deleted: ");
                        scanf("%s", f);
                        for(int j=0;j<dir[i].fileCount;j++){
                            if(!strcmp(f,dir[i].files[j].filename)){
                                found_file=1;
                                for(int k=dir[i].files[j].startBlock;k<(dir[i].files[j].startBlock+dir[i].files[j].len);k++){
                                    blocks[k]=0;
                                }
                            }
                        }
                        if(found_file==1){
                            printf("File deleted\n");
                            dir[i].fileCount--;
                        } else {
                            printf("File does not exist\n");
                        }
                    }
                }
                if(found_dir==0){
                    printf("Directory not found!\n");
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != 5);
}
