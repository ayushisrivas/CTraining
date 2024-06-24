#include<stdio.h>
#include<limits.h>
int main(){
	int n,m,i;
	printf("Enter the length of array 1: \n");
	scanf("%d",&n);

	printf("Enter the length of array 2: \n");
	scanf("%d",&m);

	int arr1[n],arr2[m],arr3[n+m];

	printf("Enter first array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("Enter second array:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr2[i]);
	}
	for(i=0;i<n;i++)
	{
		arr3[i]=arr1[i];
	}
	for(i = n; i<n+m; i++)
	{
		arr3[i]=arr2[i-n];
	}
	printf("The updated array is:\n");
	for(i =0;i<n+m;i++)
	{
		printf("%d ", arr3[i]);
	}
       return 0;
}       
	

