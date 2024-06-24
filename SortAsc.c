#include<stdio.h>
#include<limits.h>
int main(){
	int n,i,j,temp;
	printf("Enter the length of array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d integers.\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(arr[i]<arr[j])
			{	temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}	
	}
	printf("The sorted array is:\n");
	for(i =0;i<n;i++){
		printf("%d ", arr[i]);
	}
       return 0;
}       
	

