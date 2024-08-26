#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[20];
    int number;
    int total_mark;
    struct node* link;
};

void print(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        struct node* temp = head;
        while (temp != NULL)
        {
            printf("\nName = %s \n",temp->name);
            printf("Rollno = %d\n",temp->number);
            printf("Mark = %d\n",temp->total_mark);
            temp = temp->link;
        }
    }
}


struct node* add_beg(struct node* head,char name[20],int number,int total_marks)
{
   struct node* ptr = malloc(sizeof(struct node));
   strcpy(ptr->name,name);
   ptr->number = number;
   ptr->total_mark= total_marks;
   ptr->link = head;
   head = ptr;
   return(head);
}
struct node* add_last(struct node* head,char name[20],int number,int total_marks)
{
    struct node *ptr ,*temp;
    ptr = malloc(sizeof(struct node));
    strcpy(ptr->name,name);
    ptr->number = number;
    ptr->total_mark= total_marks;
    ptr->link = NULL;
    temp = head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
   temp->link = ptr;
    return(head);
}
void add_pos(struct node* head, char name[20],int number,int total_marks,int pos)
{
    struct node *ptr ,*temp;
    ptr = malloc(sizeof(struct node));
    strcpy(ptr->name,name);
    ptr->number = number;
    ptr->total_mark= total_marks;
    ptr->link = NULL;
    temp = head;
    pos--;   
    while(pos!=1)
    {
       temp = temp->link;
        pos--;
    }
    ptr->link = temp->link;
    temp->link = ptr;
   
}
struct node* delete(struct node *head,int del_no)
{
    struct node *ptr = head;
    struct node *prev = head;
    while(ptr->number != del_no && ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    if (ptr->number != del_no)
    {
        printf("The key value does not match");
    }

    else
    {
        if (ptr == head)
        {
            head = ptr->link;
            free (ptr);
        }
        else
        {
            prev->link = ptr->link;
            free(ptr);    
        }
        
    }
    return(head);
}
void search(struct node *head,int  key)
{
    struct node *ptr = head;
    while(ptr->number != key && ptr->link != NULL)
    {
       ptr = ptr->link; 
    }
    if (ptr->number == key)
    {
        printf("The element is found\n");
        printf("Name = %s \n",ptr->name);
        printf("Rollno = %d\n",ptr->number);
        printf("Mark = %d\n",ptr->total_mark);
    }
    else
    {
        printf("The element is not found");
    }
}
void swap_rollno(struct node* a,struct node* b)
{
   int temp;
    temp = a->number;
    a->number = b->number;
    b->number = temp;
}
void swap_name(struct node* a,struct node* b)
{
    char temp[20];
    strcpy(temp,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp);
}
void swap_total_marks(struct node* a,struct node* b)
{
    int temp;
    temp = a->total_mark;
    a->total_mark = b->total_mark;
    b->total_mark = temp;
}
struct node* sort(struct node* head)
{
    struct node* temp = head;
    while (temp->link != NULL)
    {
        struct node* ptr = temp->link;
        while(ptr != NULL)
        {
            if (temp->number > ptr->number)
            {
                swap_name(temp,ptr);
                swap_rollno(temp,ptr);
                swap_total_marks(temp,ptr);
            }
            ptr = ptr->link;
        }
        temp = temp->link;
    }
    return(head);

}

int main ()
{
    struct node* head = NULL;
    int n,number,total_marks,ins,pos,del_no,key;
    char name[20];
    
    printf("Enter no of students to be added");
    scanf("%d",&n);

    while(n != 0)
    {
        if (head == NULL)
        {
            printf("Enter name :");
            scanf("%s",name);
            printf("Enter roll no:");
            scanf("%d",&number);
            printf("Enter Total marks");
            scanf("%d",&total_marks);
            head = add_beg(head,name,number,total_marks);
            n--;
        }

        else
        {
            printf("Enter name :");
            scanf("%s",name);            
            printf("Enter roll no:");
            scanf("%d",&number);
            printf("Enter Total marks");
            scanf("%d",&total_marks); 
            head = add_last(head,name,number,total_marks);  
            n--;
        }
    }
    printf("1. insert\n2.delete\n3.sort\n4.search\n5.display\n");
    printf("Enter your choice");
    scanf("%d",&n);

    switch (n)
    {
        case 1:
            printf("Enter name :");
            scanf("%s",name);
            printf("Enter roll no:");
            scanf("%d",&number);
            printf("Enter Total marks");
            scanf("%d",&total_marks); 
            printf("enter where do u want to insert \n1.begining\n2.end\n3.postion");
            scanf("%d",&ins);
            switch (ins)
            {
                case 1:
                    head = add_beg(head,name,number,total_marks);
                    print(head);
                    break;
                case 2:
                    head = add_last(head,name,number,total_marks); 
                    print(head);
                    break;
                case 3:
                    printf("Enter postion");
                    scanf("%d",&pos);
                    add_pos(head,name,number,total_marks,pos);
                    print(head);                      
            }
            break;      

        case 2:
            printf("Enter the Roll number to be deleted:");
            scanf("%d",&del_no);
            head = delete(head,del_no);
            print(head);
            break;

        case 3 :
            head = sort(head);
            print(head);
            break;    

        case 4 :
            printf("Enter rollno to be searched:");
            scanf("%d",&key);
            search(head,key);
            print(head);
            break;

        case 5 :
            print(head);
            break;  
    }
    return(0);
}