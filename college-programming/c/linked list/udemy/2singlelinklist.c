#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *link;
};

int main()
{
    struct node *head = NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->value=45;
    head->link=NULL;

    struct node *next = NULL;
    next=(struct node *)malloc(sizeof(struct node));
    next->value=12;
    next->link=NULL;
    head->link=next;

    next=(struct node *)malloc(sizeof(struct node));
    next->value=13;
    next->link=NULL;

    head->link->link=next;

    return 0;



}