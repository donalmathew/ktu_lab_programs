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
	int mid;
	int l=0,h=n;
	int f=0;
	int ser;
	printf("Enter the element to be searched: ");
	scanf("%d",&ser);
	while(l!=h)
	{
		mid=(l+h)/2;
		if(ser==a[mid])
		{
			printf("Element is found at %d position",mid+1);
			f=1;
			break;
		}
		else if(ser<a[mid])
		{
			h=mid-1;
			l=0;
		}
		else if(ser>a[mid])
		{
			l=mid+1;
			h=n;
		}
	}
	if(f!=1)
	{
		printf("Element not found");
	}
	return(0);
}
