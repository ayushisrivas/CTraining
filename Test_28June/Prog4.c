//Input 2 arrays in sorted order and merge them. The merged array should also be sorted.
#include<stdio.h>
int main()
{
	int a,i=0,j=0,k=0;
	printf("Enter the length of arrays: ");
	scanf("%d",&a);
	getchar();
	int arr1[a],arr2[a],arr3[2*a];
	printf("Enter the sorted elements of array 1: ");
	for(int i=0;i<a;i++)
	{
		scanf("%d",&arr1[i]);
		getchar();
	}
	printf("Enter the sorted elements of array 2: ");
	for(int i=0;i<a;i++)
	{
		scanf("%d",&arr2[i]);
		getchar();
	}
	i=0;
	for(i,j;i<a,j<a;)
	{
		if(arr1[i]<arr2[j])
		{
			arr3[k]=arr1[i];
			i++;
			k++;
		}
		else if(arr1[i]>arr2[j])
		{
			arr3[k]=arr2[j];
			j++;
			k++;
		}
		else
		{
			arr3[k]=arr1[i];
			arr3[k+1]=arr1[i];
			k+=2;
		}
	}
	if(i<j)
	{
		for(i;i<2*a;i++)
		{
			arr3[i+a-1]=arr1[i];
		}
	}
	else if(j>i)
	{
		for(j;j<2*a;j++)
		{
			arr3[j+a-1]=arr2[j];
		}
	}


	printf("The sorted array is: \n");
	for(i=0;i<a*2;i++)
	{
		printf("%d  ",arr3[i]);
	}
	return 0;
}
				


