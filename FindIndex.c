#include<stdio.h>
#include<limits.h>
int main(){
	int n,i,k,f=0;
	printf("Enter the length of array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d integers.\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to be searched: \n");
	scanf("%d",&k);

	for(int i=0;i<n;i++)
	{
		if(k==arr[i])
		{
			printf("Element found at : %d", i+1);
			f=1;
			break;
		}
	}
	if(f==0)
		printf("Element not found!");
       return 0;
}       
	

