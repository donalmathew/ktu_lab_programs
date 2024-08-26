#include<stdio.h>
int main()
{
	int n,i,j;
	int a[20];
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return(0);
}
