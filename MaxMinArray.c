#include<stdio.h>
#include<limits.h>
int main(){
	int n, max=INT_MIN, min=INT_MAX	,i;
	printf("Enter the length of array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d integers.\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(min>arr[i])
		{
			min=arr[i];
		}
		if (max<arr[i]){
			max=arr[i];
		}
	}

	printf("The maximum and minimum are: %d , %d ", max,min);
		

       return 0;
}       
	

