#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head;

void print()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}

void insert(int data, int pos)
{
    struct node* temp1= (struct node*)malloc(sizeof(struct node*));
    temp1->data=data;
    temp1->next=NULL;

    //for entering 1st value
    if(pos==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }     

    //for all other cases
    struct node* temp2=head;
    int i;
    for(i=0;i<pos-2;i++)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

int main()
{
    head=NULL;
    //printf("enter the values to be inserted");
    insert(2,1);
    insert(3,2);
    print();
    return 0;
}