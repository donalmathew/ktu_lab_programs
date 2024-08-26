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
    File files[MAX_FILES];
    int fileCount;
};

typedef struct Directory Directory;
int blocks[MAX_BLOCKS]={0};

void main() {
    Directory dir;
    dir.fileCount = 0;

    int choice,flag=0;
    do {
        printf("\n--- Single-Level Directory File Organization ---\n");
        printf("1. Add File\n");
        printf("2. Display Directory\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (dir.fileCount >= MAX_FILES) {
                    printf("Directory is full. Cannot add more files.\n");
                    break;
                }

                char filename[MAX_FILENAME];
                int startBlock, len, count=0;
                printf("Enter filename: ");
                scanf("%s", filename);
                for(int i=0;i<dir.fileCount;i++){
                    if(!strcmp(filename,dir.files[i].filename)){
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

                if (dir.fileCount < MAX_FILES && flag==0) {
                    strcpy(dir.files[dir.fileCount].filename, filename);
                    dir.files[dir.fileCount].startBlock = startBlock;
                    dir.files[dir.fileCount].len = len;
                    
                    dir.fileCount++;
                    printf("File '%s' added to the directory.\n", filename);
                } else {
                    printf("Directory is full. Cannot add more files.\n");
                }
                break;

            case 2:
                printf("Files in the directory:\n");
                for (int i = 0; i < dir.fileCount; i++) {
                    printf("File: %s | Start Block: %d | End Block: %d\n",
                        dir.files[i].filename, dir.files[i].startBlock, (dir.files[i].startBlock+dir.files[i].len));
                }
                break;

            case 3:
                int found=0;
                printf("Enter the file name to be deleted: ");
                scanf("%s", filename);
                for(int i=0;i<dir.fileCount;i++){
                    if(!strcmp(filename,dir.files[i].filename)){
                        found=1;
                        for(int j=dir.files[i].startBlock;j<(dir.files[i].startBlock+dir.files[i].len);j++){
                            blocks[j]=0;
                        }
                    }
                }
                if(found==1){
                    printf("File deleted\n");
                    dir.fileCount--;
                } else {
                    printf("File does not exist\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != 4);
}
