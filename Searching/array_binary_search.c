#include <stdio.h>
int main ()
{
	int a[50],n,i,first,last,key,mid;
	printf ("Enter the number of elements:");
	scanf ("%d",&n);
	printf ("Enter array elements:\n");
	for (i=0;i<n;i++)
	{
		scanf ("%d",&a[i]);
	}
	printf ("Enter an element:");
	scanf ("%d",&key);
	first=0;
	last=n-1;
	mid=(first+last)/2;
	while (first<=last)
	{
		if (a[mid]>key)
		{
			last=mid-1;
		}
		else if (a[mid]==key)
		{
			printf ("%d is found at %d position",key,mid+1);
			break;
		}
		else
		{
			first=mid+1;
		}
		mid=(first+last)/2;
	}
	if (first>last)
	{
		printf ("Item not found");
	}
	return 0;
}
