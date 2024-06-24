#include<stdio.h>
#include<limits.h>
int main(){
	int n,i,j,k,temp;
	printf("Enter the length of the array: \n");
	scanf("%d",&n);
	printf("Enter the amount of left rotation: \n");
	scanf("%d",&k);
	int arr[n];
	printf("Enter the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<k;i++)
	{
		temp = arr[0];
		for(int j=0;j<n-1;j++)
		{
			arr[j]=arr[j+1];		
		}
		arr[n-1]=temp;	
	}
	printf("The updated array is: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
       return 0;
}       
	

