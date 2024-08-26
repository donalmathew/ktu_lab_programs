#include<stdio.h>
struct elmt
{
	int row;
	int col;
	int val;
}tup1[50],tup2[50],tup3[50],a[50],b[50];
void read(int a[10][10],int n,int m);
void display(int a[10][10],int n,int m);
void disTup(struct elmt tup1[50],int n);
int sum(struct elmt tup1[50],struct elmt tup2[50],int s1,int s2);
void transpose(struct elmt a[50],int s);
int main()
{
	int A[10][10],B[10][10];
	int n1,m1,n2,m2,n3,m3;int i,j,k=1;
	printf("Enter the size of first matrix: ");
	scanf("%d",&n1);
	scanf("%d",&m1);
	read(A,n1,m1);
	printf("Enter the size of second matrix: ");
	scanf("%d",&n2);
	scanf("%d",&m2);
	read(B,n2,m2);
	int size1=0,size2=0;
	tup1[0].row=n1;
	tup1[0].col=m1;
	if(n1>n2)
	tup3[0].row=n1;
	else
	tup3[0].row=n2;
	if(m1>m2)
	tup3[0].col=m1;
	else
	tup3[0].col=m2;
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			if(A[i][j]!=0)
			{
				tup1[k].row=i;
				tup1[k].col=j;
				tup1[k].val=A[i][j];
				k++;
				size1=size1+1;
			}
		}
	}
	tup1[0].val=size1;
	tup2[0].row=n2;
	tup2[0].col=m2;
	k=1;
	for(i=0;i<n2;i++)
	{
		for(j=0;j<m2;j++)
		{
			if(B[i][j]!=0)
			{
				tup2[k].row=i;
				tup2[k].col=j;
				tup2[k].val=B[i][j];
				k++;
				size2=size2+1;
			}
		}
	}
	tup2[0].val=size2;
	printf("The first matrix is: \n");
	display(A,n1,m1);
	printf("the tuple form is: \n");
	disTup(tup1,size1);
	printf("the transpose is: \n");
	transpose(tup1,size1);
	printf("The second matrix is: \n");
	display(B,n2,m2);
	printf("the tuple form is: \n");
	disTup(tup2,size2);
	printf("the transpose is: \n");
	transpose(tup2,size2);
	int t=sum(tup1,tup2,size1,size2);
	printf("The sum is:\n");
	disTup(tup3,t-1);
}
void read(int a[10][10],int n,int m)
{
	printf("Enter the elements: ");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void display(int a[10][10],int n,int m)
{	
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void disTup(struct elmt tup1[50],int n)
{
	int i;
	for(i=0;i<n+1;i++)
	{
		printf("%d\t%d\t%d",tup1[i].row,tup1[i].col,tup1[i].val);
		printf("\n");
	}
}
int sum(struct elmt tup1[50],struct elmt tup2[50],int s1,int s2)
{
	int i=1,j=1,k=1;
	int n1=s1;
	int n2=s2;
	while(i<=n1 && j<=n2)
	{
		if(tup1[i].row==tup2[j].row && tup1[i].col==tup2[j].col)
		{
			tup3[k].val=tup1[i].val+tup2[j].val;
			tup3[k].row=tup1[i].row;
			tup3[k].col=tup1[i].col;
			i++;j++;k++;
		}
		else if(tup1[i].row<tup2[j].row)
		{
			tup3[k].row=tup1[i].row;
			tup3[k].col=tup1[i].col;
			tup3[k].val=tup1[i].val;
			i++;k++;
		}
		else if(tup2[j].row<tup1[i].row)
		{
			tup3[k].row=tup2[j].row;
			tup3[k].col=tup2[j].col;
			tup3[k].val=tup2[j].val;
			j++;k++;
		}
		else if(tup1[i].row==tup2[j].row && tup1[i].col<tup2[j].col)
		{
			tup3[k].row=tup1[i].row;
			tup3[k].col=tup1[i].col;
			tup3[k].val=tup1[i].val;
			i++;k++;
		}
		else if(tup1[i].row==tup2[j].row && tup1[i].col>tup2[j].col)
		{
			tup3[k].row=tup2[j].row;
			tup3[k].col=tup2[j].col;
			tup3[k].val=tup2[j].val;
			j++;k++;
		}
	}
	while(j<=n2)
	{
		if(i>n1)
		{
			tup3[k].row=tup2[j].row;
			tup3[k].col=tup2[j].col;
			tup3[k].val=tup2[j].val;
			j++;k++;
		}
	}
	while(i<=n1)
	{
		if(j>n2)
		{
			tup3[k].row=tup1[i].row;
			tup3[k].col=tup1[i].col;
			tup3[k].val=tup1[i].val;
			i++;k++;
		}
	}
	tup3[0].val=k-1;
	return(k);
}
void transpose(struct elmt a[50],int s)
{
	int n,i,j,currentb=1;
	n=a[0].val;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].val=n;
	if(n>0)
	{
		for(i=0;i<a[0].col;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[j].col==i)
				{
					b[currentb].row=a[j].col;
					b[currentb].col=a[j].row;
					b[currentb].val=a[j].val;
					currentb++;
				}
			}
		}
	}
	disTup(b,s);
}	
