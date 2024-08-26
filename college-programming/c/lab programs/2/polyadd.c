#include<stdio.h>
struct poly
{
	int exp;
	int coeff;
};
int main()
{
	int n1,n2,i,j,k;
	struct poly p1[20],p2[20],p3[20],temp[20];
	printf("Enter the no of terms in first polynomial: ");
	scanf("%d",&n1);
	printf("Enter the no of terms in second polynomial: ");
	scanf("%d",&n2);
	
	printf("Enter the elements of the first polynomial: \n");
	for(i=0;i<n1;i++)
	{
		printf("Enter the %d coefficient: ",i+1);
		scanf("%d",&p1[i].coeff);
		printf("Enter the %d exponent: ",i+1);
		scanf("%d",&p1[i].exp);
	}
	
	printf("Enter the elements of the second polynomial: \n");
	for(i=0;i<n2;i++)
	{
		printf("Enter the %d coefficient: ",i+1);
		scanf("%d",&p2[i].coeff);
		printf("Enter the %d exponent: ",i+1);
		scanf("%d",&p2[i].exp);
	}
	
	/*for(i=0;i<n1-1;i++)
	{
		for(j=0;j<n1-1-i;j++)
		{
			if(p1[j].coeff<p1[j+1].coeff)
			{
				temp[j].coeff=p1[j].coeff;
				p1[j].coeff=p1[j+1].coeff;
				p1[j+1].coeff=temp[j].coeff;
				
				temp[j].exp=p1[j].exp;
				p1[j].exp=p1[j+1].exp;
				p1[j+1].exp=temp[j].exp;
			}
		}
	}
	
	for(i=0;i<n2-1;i++)
	{
		for(j=0;j<n2-1-i;j++)
		{
			if(p2[j].coeff>p2[j+1].coeff)
			{
				temp[j].coeff=p2[j].coeff;
				p2[j].coeff=p2[j+1].coeff;
				p2[j+1].coeff=temp[j].coeff;
				
				temp[j].exp=p2[j].exp;
				p2[j].exp=p2[j+1].exp;
				p2[j+1].exp=temp[j].exp;
			}
		}
	}*/
	
	i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(p1[i].exp==p2[j].exp)
		{
			p3[k].exp=p1[i].exp;
			p3[k].coeff=p1[i].coeff+p2[j].coeff;
			i++;
			j++;
			k++;
		}
		else if(p1[i].exp>p2[j].exp)
		{
			p3[k].exp=p1[i].exp;
			p3[k].coeff=p1[i].coeff;
			i++;
			k++;
		}
		else if(p2[j].exp>p1[i].exp)
		{
			p3[k].exp=p2[j].exp;
			p3[k].coeff=p2[j].coeff;
			j++;
			k++;
		}
	}
	while(i<n1)
		{
			p3[k].exp=p1[i].exp;
			p3[k].coeff=p1[i].coeff;
			i++;
			k++;
		}
		while(j<n2)
		{
			p3[k].exp=p2[j].exp;
			p3[k].coeff=p2[j].coeff;
			j++;
			k++;
	}
	printf("The first polynomial is: ");
	for(i=0;i<n1-1;i++)
	{
		printf("%dx^%d +",p1[i].coeff,p1[i].exp);
	}
	printf("%dx^%d",p1[n1-1].coeff,p1[n1-1].exp);
	
	printf("\nThe second polynomial is: ");
	for(i=0;i<n2-1;i++)
	{
		printf("%dx^%d + ",p2[i].coeff,p2[i].exp);
	}
	printf("%dx^%d",p2[n2-1].coeff,p2[n2-1].exp);
	
	printf("\nThe sum is: ");
	for(i=0;i<k-1;i++)
	{
		printf("%dx^%d + ",p3[i].coeff,p3[i].exp);
	}	
	printf("%dx^%d",p3[k-1].coeff,p3[k-1].exp);	
}
