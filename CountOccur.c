
#include<stdio.h>
#include<limits.h>
int main(){
	int n,count,i,j;
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
		count=0;
		for(int j=0;j<n;j++)
		{
			if(arr[i]==arr[j])
				count++;
		}
		arr2[i]=count;
	}
	for(int i=0;i<n;i++)
	{
		printf("The frequency of %d is: %d\n", arr[i],arr2[i]);
	}
       return 0;
}       
	

