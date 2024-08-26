#include<stdio.h>
int main()
{
	int n,i,f;int a[20];int ser;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&ser);
	for(i=0;i<n;i++)
	{
		if(a[i]==ser)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	printf("Number found");
	else
	printf("Number not found");
	return(0);
}
