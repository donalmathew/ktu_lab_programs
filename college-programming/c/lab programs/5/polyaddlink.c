#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head,int coeff,int expo)
{
   // printf("hello");
    struct node* new = malloc(sizeof(struct node));
    struct node* temp = NULL;
    new->expo = expo;
    new->coeff = coeff;
    new->link = NULL;
   if(head == NULL || head->expo <expo)
    {
        new->link = head;
        head = new;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp-> link->expo >= expo)
        {
            temp = temp->link;
        }
        new ->link = temp->link;
        temp->link = new;
    }

    return (head);
}
struct node* create(struct node* head)
{
    int i,n,coeff,expo;
    printf("enter the no of terms :");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coeff:");
        scanf("%d",&coeff);
        printf("Enter expo");
        scanf("%d",&expo);
        head = insert(head,coeff,expo);
    }
 
    return(head);
}

void  print(struct node* head)
{
    if (head == NULL)
    {
        printf("No Polynomial");
    }
    else
    {
        struct node* temp = head;
        while (temp != NULL)
        {
            printf("(%dx^%d)",temp->coeff,temp->expo);
            temp = temp->link;
            if (temp->link != NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void polyadd(struct node *head1,struct node *head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *head3 = NULL;
    head3 = malloc(sizeof(struct node));
 
    while(temp1 != NULL && temp2 != NULL)
    {
        if (temp1->expo == temp2->expo)
        {
            head3 = insert(head3,temp1->coeff + temp2->coeff,temp1->expo);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else
        {
            if (temp1->expo > temp2->expo)
            {
                head3 = insert(head3,temp1->coeff,temp1->expo);
                temp1 = temp1->link;
            }
            else 
            {
                head3 = insert(head3,temp2->coeff,temp2->expo);
                temp2 = temp2->link;
            }
        } 
    }
    while (temp1 != NULL)
    {
        head3 = insert(head3,temp1->coeff,temp1->expo);
        temp1 = temp1->link;
    }
    while(temp2 != NULL)
    {
        head3 = insert(head3,temp2->coeff,temp2->expo);
        temp2 = temp2->link;
    }
    print(head3);
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter polynomial 1\n");
    head1 = create(head1);
    printf("Enter polynomial 2\n");
    head2 = create(head2);
    polyadd(head1,head2);
    return(0);

}
