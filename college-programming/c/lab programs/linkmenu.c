#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
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
            printf("%d\n",temp->data);
            temp = temp->link;
        }
    }
}
struct node* add_beg(struct node* head,int data)
{
   struct node* ptr = malloc(sizeof(struct node));
   ptr->data = data;
   ptr->link = head;
   head = ptr;
   return(head);
}
struct node* add_last(struct node* head,int data)
{
    struct node *ptr ,*temp;
    temp = malloc(sizeof(struct node));
    temp-> data = data;
    temp->link = NULL;
    ptr = head;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return(head);
}
void add_pos(struct node* head, int data,int pos)
{
    struct node *ptr ,*temp;
    temp = malloc(sizeof(struct node));
    temp-> data = data;
    temp->link = NULL;
    ptr = head;
    pos--;   
    while(pos!=1)
    {
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
   
}
struct node* del_first(struct node* head)
{
    if(head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        struct node *temp = head;
        head = temp->link;
        free(temp);
    }
    return(head);
}
struct node* del_last(struct node* head)
{
    struct node *ptr,*temp;
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *temp,*ptr;
            temp = head;
            ptr = head;
            while(temp->link != NULL)
            {
                ptr = temp;
                temp = temp->link;
            }
            ptr->link = NULL;
            free(temp);   
        }
    }
    return(head);
}
struct node* del_pos(struct node* head,int pos)
{
    
    struct node* current = head;
    struct node* prev = head;
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        if (pos == 1)
        {
            head = current->link;
            free(current);
            current = NULL;
        }
        else
        {
            while (pos!=1)
            {
                prev = current;
                current = current->link;
                pos--;
            }
            prev->link = current->link;
            free(current);
        }
    }
}

int main()
{
    struct node* head =  malloc(sizeof(struct node));
    head->data = 15;
    struct node* current = malloc(sizeof(struct node));
    current->data = 100;
    head->link = current;
    current =  malloc(sizeof(struct node));
    current->data = 147;
    current ->link = NULL;
    head->link->link = current;
    print(head);
    printf("These are the data's available\n");
    printf ("operations available:\n1.Display\n2.Insert at Beginning\n3.Insert at End\n4.Insert at a specified Position\n5.Delete from Beginning \n6.Delete from End \n7.Delete from a specified Position\n");
    int n,data,pos;
    printf("Enter your choice:");
    scanf("%d",&n);
    switch (n)
    {
        case 1:
            print(head);
            break;
        case 2:
            printf("Enter data to be added:");
            scanf("%d",&data);
            head = add_beg(head,data);
            print(head);
            break;
        case 3:
            printf("Enter data to be added:");
            scanf("%d",&data);
            head = add_last(head,data);
            print(head);
            break;
        case 4:
            printf("Enter data to be added:");
            scanf("%d",&data);
            printf("Enter the postion to be added:");
            scanf("%d",&pos);
            add_pos(head,data,pos);
            print(head);
            break;
        case 5:
            head = del_first(head);
            print(head);
            break;
        case 6:
            head = del_last(head);
            print(head);
            break;
        case 7:
            printf("Enter the postion to be deleted:");
            scanf("%d",&pos);
            head = del_pos(head,pos);
            print(head);
            break;
    }

    return (0);

}
