#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *link;
}*start;

void create(int);
void display();

void main()
{
    start = NULL;
    
    int choice, data, choice1, pos;
    while(1)
    {
        system("cls"); //clrscr
        printf("\n1.create linked list");
        printf("\n2.display linked list");
        printf("\n3.exit");
        printf("\nenter a value");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nenter data for first node");
            scanf("%d",&data);
            break;

            case 2:
            display();
            break;

            case 3:
            exit(1);

            deafault:
            printf("\n invalid entry");

        }
    }
}

void create(int data)
{
    system("cls");
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    if(start==NULL)
    {
        temp->info=data;
        temp->link=NULL;
        start=temp;
    }
    printf("\nlist created");
   
}

void display()
{
    struct node *ptr;
    ptr=start;
    system("cls");
    if(start==NULL)
    {
        printf("\nlist is empty");
        
        return;
    }
    printf("\nlinked list");
    while(ptr!=NULL);
    {
        printf("%d->",ptr->info);
        ptr=ptr->link;
    }
    printf("\nend of list");
    
    system("cls");


}


