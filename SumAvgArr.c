
#include<stdio.h>
#include<limits.h>
int main(){
	int n, sum=0,i;
	float avg;
	printf("Enter the length of array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d integers.\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	avg=(float)sum/n;
	printf("The sum and average are: %d , %.2f ", sum,avg);
		

       return 0;
}       
	

