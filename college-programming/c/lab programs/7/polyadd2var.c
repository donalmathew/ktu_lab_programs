
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,x_exp,y_exp;
    struct node *next;
};

struct node *Phead,*Qhead,*Rhead;

//read polynomial
struct node *ReadPoly()
{
    struct node *new,*ptr,*head=NULL;
    int n,i;
    
    printf("enter no of terms of polynomial");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("enter the coefficient and exponent of x and y\n");
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&new->coef);
        scanf("%d",&new->x_exp);
        scanf("%d",&new->y_exp);
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            ptr=head;
        }
        else
        {
            ptr->next=new;
            ptr=new;
        }
    }
     return(head);
}
//display the polynomial
 void DisplayPoly(struct node *head)
    {
        struct node *ptr;
        if(head==NULL)
        printf("polynomial is empty");
        else
        {
            ptr=head;
            while(ptr->next !=NULL)
            {
                printf("%dx^%dy^%d + ",ptr->coef,ptr->x_exp,ptr->y_exp);
                ptr=ptr->next;
            }
            printf("%dx^%dy^%d",ptr->coef,ptr->x_exp,ptr->y_exp);
        }
    }
//add polynomials
struct node *AddPoly()
    {
        struct node *new,*P,*Q,*R,*head=NULL;
        P=Phead;
        Q=Qhead;
        while(P!=NULL && Q!=NULL)
        {
            if(P->x_exp==Q->x_exp&&P->y_exp==Q->y_exp)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=P->coef+Q->coef;
                new->x_exp=P->x_exp;
                new->y_exp=P->y_exp;
                new->next=NULL;
                P=P->next;
                Q=Q->next;
            }
            else if(P->x_exp>Q->x_exp)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=P->coef;
                new->x_exp=P->x_exp;
                new->y_exp=P->y_exp;
                new->next=NULL;
                P=P->next;
            }
            else if(P->x_exp<Q->x_exp)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=Q->coef;
                new->x_exp=Q->x_exp;
                new->y_exp=Q->y_exp;
                new->next=NULL;
                Q=Q->next;
            }
            else if(P->y_exp>Q->y_exp)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=P->coef;
                new->x_exp=P->x_exp;
                new->y_exp=P->y_exp;
                new->next=NULL;
                P=P->next;
            }
            else 
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=Q->coef;
                new->x_exp=Q->x_exp;
                new->y_exp=Q->y_exp;
                new->next=NULL;
                Q=Q->next;
            }
            if(head==NULL)
                {
                    head=new;
                    R=head;
                }
                else
                 {
                    R->next=new;
                    R=new;
                }
        }
    while(P!=NULL)
        {
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=P->coef;
            new->x_exp=P->x_exp;
            new->y_exp=P->y_exp;
            new->next=NULL;
            if(head==NULL)
            {
                head=new;
                R=head;
            }
            else
            {
                R->next=new;
                R=new;
            }
            P=P->next;
        }
        while(Q!=NULL)
        {
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=Q->coef;
            new->x_exp=Q->x_exp;
            new->y_exp=Q->y_exp;
            new->next=NULL;
            if(head==NULL)
            {
                head=new;
                R=head;
            }
            else
            {
                R->next=new;
                R=new;
            }
            Q=Q->next;
        }
        return(head);
    }
//main function    
void main()
{
    printf("enter details of first polynomaial \n");
    Phead=ReadPoly();
     printf("enter details of second polynomaial \n");
     Qhead=ReadPoly();
     //display the polynomials
     printf("\n First Polynomial: \n");
     DisplayPoly(Phead);
     printf("\n second Polynomial: \n");
     DisplayPoly(Qhead);
     //display the sum
     Rhead=AddPoly();
     printf("\nthe sum is:\t");
     DisplayPoly(Rhead);     
}
