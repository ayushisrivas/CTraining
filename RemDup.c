#include<stdio.h>
#include<limits.h>
int main(){
	int n,i,j,k;
	printf("Enter the length of the array: \n");
	scanf("%d",&n);
	int arr[n],arr2[n];
	printf("Enter first array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				for(int k=j;k<n;k++)
				{
					arr[k]=arr[k+1];
				}
				n--;
			}
		}
	}
	printf("The updated array is: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
       return 0;
}       
	

