

#include<stdio.h>
#include<limits.h>
int main(){
	int n,i,j,temp;
	printf("Enter the length of array: \n");
	scanf("%d",&n);
	int arr[n];
	j=n-1;
	printf("Enter %d integers.\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for (i=0;i<n/2;i++){
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	j--;	
	}
	printf("The reversed array is: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
       return 0;
}       
	
