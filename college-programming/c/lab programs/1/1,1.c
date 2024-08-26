#include<stdio.h>
int main()
{
	int n,i,j,temp;int a[20];
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return(1);
}
