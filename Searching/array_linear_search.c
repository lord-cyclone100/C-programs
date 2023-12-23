#include <stdio.h>
int main()
{
	int a[50],b,i,key,flag=0;
	printf ("Enter the number of elements:");
	scanf ("%d",&b);
	printf("Enter array elements:\n");
	for (i=0;i<b;i++)
	{
		scanf ("%d",&a[i]);
	}
	printf ("Enter an element:");
	scanf ("%d",&key);
	for (i=0;i<b;i++)
	{
		if (key==a[i])
		{
			flag=1;
		}
	}
	if (flag==1)
	{
		printf ("The entered element is present in the array");
	}
	else
	{
		printf ("The entered element is not present in the array");
	}
	return 0;
}
