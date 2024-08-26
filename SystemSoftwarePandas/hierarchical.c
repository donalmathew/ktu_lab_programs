#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BLOCKS 32


int blocks[MAX_BLOCKS]={0};

// Structure for a file
struct File {
    char name[50];
    int startBlock,len;
    // You can include other file attributes here
};

// Structure for a directory node
struct DirectoryNode {
    char name[50];
    struct File files[100]; // Assuming each directory can hold up to 100 files
    int fileCount;
    struct DirectoryNode* subdirectories[100]; // Assuming each directory can have up to 100 subdirectories
    int subdirectoryCount;
};

// Function to create a directory node
struct DirectoryNode* createDirectoryNode(char name[]) {
    struct DirectoryNode* newNode = (struct DirectoryNode*)malloc(sizeof(struct DirectoryNode));
    strcpy(newNode->name, name);
    newNode->fileCount = 0;
    newNode->subdirectoryCount = 0;
    return newNode;
}

// Function to create a file
struct File createFile(char name[]) {
    struct File newFile;
    strcpy(newFile.name, name);
    return newFile;
}

// Function to add a subdirectory to a directory
void addSubdirectory(struct DirectoryNode* parentDir, struct DirectoryNode* subDir) {
    parentDir->subdirectories[parentDir->subdirectoryCount++] = subDir;
}

// Function to display the hierarchical directory structure
void printDirectory(struct DirectoryNode* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("|-- ");
    }
    printf("%s\n", node->name);

    for (int i = 0; i < node->fileCount; i++) {
        for (int j = 0; j < depth + 1; j++) {
            printf("|   ");
        }
        printf("|-- %s\n", node->files[i].name);
    }

    for (int i = 0; i < node->subdirectoryCount; i++) {
        printDirectory(node->subdirectories[i], depth + 1);
    }
}

// Function to add a file to a directory
void addFile(struct DirectoryNode* dir, struct File file) {
    dir->files[dir->fileCount] = file;
    int flag=0;
    int startBlock, len, count=0;
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
            dir->files[dir->fileCount].startBlock-startBlock;
            dir->files[dir->fileCount++].len=len;
            break;
        } else {
            printf("Blocks already allocated. Enter another block\n");
        }
    }
}

// Function to add a subdirectory to a directory
void addDirectory(struct DirectoryNode* parentDir, struct DirectoryNode* subDir) {
    parentDir->subdirectories[parentDir->subdirectoryCount++] = subDir;
}

// Function to delete a file from a directory
void deleteFile(struct DirectoryNode* dir, char name[]) {
    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            for(int k=dir->files[i].startBlock;k<(dir->files[i].startBlock+dir->files[i].len);k++){
                blocks[k]=0;
            }
            // Shift files to the left to remove the deleted file
            for (int j = i; j < dir->fileCount - 1; j++) {
                dir->files[j] = dir->files[j + 1];
            }
            dir->fileCount--;
            break;
        }
    }
}

// Function to delete a subdirectory from a directory
void deleteDirectory(struct DirectoryNode* parentDir, char name[]) {
    for (int i = 0; i < parentDir->subdirectoryCount; i++) {
        if (strcmp(parentDir->subdirectories[i]->name, name) == 0) {
            // Shift subdirectories to the left to remove the deleted directory
            for (int j = i; j < parentDir->subdirectoryCount - 1; j++) {
                parentDir->subdirectories[j] = parentDir->subdirectories[j + 1];
            }
            parentDir->subdirectoryCount--;
            break;
        }
    }
}

// Function to search for a file in a directory
int searchFile(struct DirectoryNode* dir, char name[]) {
    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            return 1; // File found
        }
    }
    return 0; // File not found
}

// Function to find a directory by name
struct DirectoryNode* findDirectory(struct DirectoryNode* currentDir, char name[]) {
    for (int i = 0; i < currentDir->subdirectoryCount; i++) {
        if (strcmp(currentDir->subdirectories[i]->name, name) == 0) {
            return currentDir->subdirectories[i];
        }
    }
    return NULL;
}

int main() {
    // Create the root directory
    struct DirectoryNode* root = createDirectoryNode("Root");
    struct DirectoryNode* currentDirectory = root; // Start with the root directory as the current directory

    int choice;
    char filename[50];
    char dirname[50];

    do {
        printf("\nMenu:\n");
        printf("1. Add a file\n");
        printf("2. Add a directory\n");
        printf("3. Delete a file\n");
        printf("4. Delete a directory\n");
        printf("5. Search for a file\n");
        printf("6. Change current directory\n");
        printf("7. Display directory structure\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a file
                printf("Enter file name: ");
                scanf("%s", filename);
                addFile(currentDirectory, createFile(filename));
                break;
            case 2: // Add a directory
                printf("Enter directory name: ");
                scanf("%s", dirname);
                addDirectory(currentDirectory, createDirectoryNode(dirname));
                break;
            case 3: // Delete a file
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                deleteFile(currentDirectory, filename);
                break;
            case 4: // Delete a directory
                printf("Enter directory name to delete: ");
                scanf("%s", dirname);
                deleteDirectory(currentDirectory, dirname);
                break;
            case 5: // Search for a file
                printf("Enter file name to search: ");
                scanf("%s", filename);
                if (searchFile(currentDirectory, filename)) {
                    printf("File found!\n");
                } else {
                    printf("File not found.\n");
                }
                break;
            case 6: // Change current directory
                printf("Enter directory name to change to: ");
                scanf("%s", dirname);
                struct DirectoryNode* newDirectory = findDirectory(currentDirectory, dirname);
                if (newDirectory != NULL) {
                    currentDirectory = newDirectory;
                    printf("Current directory changed to: %s\n", currentDirectory->name);
                } else {
                    printf("Directory not found.\n");
                }
                break;
            case 7: // Display directory structure
                printf("Directory Structure:\n");
                printDirectory(root, 0);
                break;
            case 8: // Exit
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    // Free allocated memory (not shown in detail in this example)
    // You should free memory to avoid memory leaks in a real program

    return 0;
}
