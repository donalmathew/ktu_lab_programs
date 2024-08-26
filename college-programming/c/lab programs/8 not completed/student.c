#include<stdio.h>
#include<stdlib.h>
struct node
    {
        int number;
        char name;
        int marks;
        struct node *next;
    };
    struct node *head,*newnode,*temp;
    struct node* head=NULL;
    
//display the details
void display()
{
    printf("\nnumber\tname\tmarks\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t%d\t%d\n",temp->number,temp->name,temp->marks);
        temp=temp->next;
    }
}

//insert 
void insert()
{
    int item, i=1;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the student number");
    scanf("%d", &newnode->number);
    printf("enter the student name");
    scanf("%d", &newnode->name);
    printf("enter the student marks");
    scanf("%d", &newnode->marks);
    temp=head;
    newnode->next=NULL;
    while (temp->number<newnode->number) 
            {
                temp = temp->next;
                i++;
            }
    newnode->next = temp->next;
    temp->next =newnode;
    printf("item inserted");
    display();
    }

//delete 
void delete()
{
    struct node *temp, *prev;
    int n;
    printf("enter the number of the student for deletion");
    scanf("%d",&n);
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        if (temp->number=n)
        {
            prev->next=temp->next;
            free(temp);
            temp->next=NULL;
        }
        
    }
    display();
} 




//search
void search()
{
    
}

//main function
int main()
{
    int choice;
    printf("enter the elements of the list\n");
    while(choice)//to create linked list
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter number");
        scanf("%d",&newnode->number);
        printf("enter name");
        scanf("%d",&newnode->name);
        printf("enter marks");
        scanf("%d",&newnode->marks);
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
        printf("\n1 Insert\n");
        printf("2 Delete\n");
        printf("3 Search\n");
        printf("4 Sort on the basis of number\n");
        printf("5 Display\n");
        printf("6 To exit\n");
        printf("Enter Option :");
        scanf("%d", &opt);
        switch (opt) 
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:search();
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
