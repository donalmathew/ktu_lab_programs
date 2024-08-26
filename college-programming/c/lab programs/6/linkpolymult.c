
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,exp;
    struct node *next;
};

struct node *Phead,*Qhead,*Rhead;

struct node *ReadPoly()
{
    struct node *new,*ptr,*head=NULL;
    int n,i;
    
    printf("enter no of terms of polynomial");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("enter the coefficients and exponents of the polynomial");
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&new->coef);
        scanf("%d",&new->exp);
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
                printf("%dx^%d + ",ptr->coef,ptr->exp);
                ptr=ptr->next;
            }
            printf("%dx^%d",ptr->coef,ptr->exp);
        }
    }
struct node *MulPoly()
    {
        struct node *new,*P,*Q,*R,*prev,*head=NULL;
        P=Phead;
        Q=Qhead;
        while(P!=NULL)
        {
            while(Q!=NULL)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=P->coef*Q->coef;
                new->exp=P->exp+Q->exp;
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
            P=P->next;
            Q=Qhead;
        }
        
        P=head;
        
        while(P!=NULL)
        {
            prev=P;
            Q=P->next;
            while(Q!=NULL)
            {
                if(P->exp==Q->exp)
                {
                    P->coef=P->coef+Q->coef;
                    prev->next=Q->next;
                    free(Q);
                    Q=prev->next;
                }
                else
                {
                    prev=Q;
                    Q=Q->next;
                }
            }
            P=P->next;
        }
        return(head);
    }
    
void main()
{
    printf("enter details of first polynomial \n");
    Phead=ReadPoly();
    printf("enter details of second polynomial \n");
    Qhead=ReadPoly();
     
    printf("\n first Polynomial: \n");
    DisplayPoly(Phead);
    printf("\n second Polynomial: \n");
    DisplayPoly(Qhead);
    Rhead=MulPoly();
    printf("the product of polynomials is : \t");
    DisplayPoly(Rhead);
}
    
        
    
