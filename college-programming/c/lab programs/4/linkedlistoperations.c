#include<stdio.h>
#include<stdlib.h>
struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*newnode,*temp;
    struct node* head=NULL;

//number of nodes
int length()
{
    int count = 0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
    
//insert at beginning
void insertbeg()
{
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter the element");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
}       

//insert at the end
void insertend()
{
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter the element");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=head;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
}

//insert at any position
void insertpos()
{
    int pos, item, i=1;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the position ");
    scanf("%d", &pos);
    printf("enter the element");
    scanf("%d", &newnode->data);
    temp=head;
    newnode->next=NULL;
    int l=length();
    if(pos>l)
        {
            printf("invalid position");
        }
    else
    {
        while (i<pos-1) 
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next =newnode;
        printf("item inserted");
    } 
}

//delete from front
void deletefront()
{ 
     if (head == NULL)
        printf("list is empty");
    else 
    {
        temp = head;
        head = head->next;
        int x = temp->data;
        printf("item deleted");
        free(temp);
    }
}

//delete from end
void deleteend()
{
    struct node *temp, *prevnode;
    if (head == NULL)
        printf("list is empty");
    else 
        {
        temp = head;
        while (temp->next != NULL) 
         {
            prevnode = temp;
            temp = temp->next;
         }
         int x = temp->data;
         printf("item deleted");
         free(temp);
         prevnode->next = NULL;
        }
}

//delete from any position
void deletepos()
{
    struct node *temp, *position;
    int i = 1, pos;
    if (head == NULL)
        printf("list is empty");
    else 
    {
        printf("enter the position");
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = head;
        int l=length();
        if(pos<1 || pos>l)
        {
            printf("invalid position");
        }
        else
          {
             if(pos==1)
              {
                  deletefront();
              }
             else
              {
                while (i < pos - 1)
                {
                temp = temp->next;
                i++;
                }
                position = temp->next;
                temp->next= position->next;
                int x = position->data;
                printf("item deleted");
                free(position);
                }
            }
    } 
}

//display the list
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//main function
int main()
{
    int choice;
    printf("enter the elements of the list\n");
    while(choice)//to create linked list
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            {
                head=temp=newnode;
            }
        else
            {
                temp->next=newnode;
                temp=newnode;
            }
        printf("enter 1 to continue, 0 to stop");
        scanf("%d",&choice);
    }
    int opt;
    while (1) 
    {
        printf("\n1 Insertion at beginning\n");
        printf("2 Insertion at end\n");
        printf("3 Insertion at any position\n");
        printf("4 Deletion at beginning\n");
        printf("5 Deletion at end\n");
        printf("6 Deletion of element at any position\n");
        printf("7 Display the list\n");
        printf("8 To exit\n");
        printf("Enter Option :");
        scanf("%d", &opt);
        switch (opt) 
        {
            case 1:insertbeg();
                   break;
            case 2:insertend();
                   break;
            case 3:insertpos();
                   break;
            case 4:deletefront();
                   break;
            case 5:deleteend();
                   break;
            case 6:deletepos();
                   break;
            case 7:display();
                   break;
            case 8:exit(1);
                   break;
            default:printf("invalid option");
        }
    }
    return 0;
}
