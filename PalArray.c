#include<stdio.h>
#include<limits.h>
int main(){
	int n,i,f=0,j;
	printf("Enter the length of array: \n");
	scanf("%d",&n);
	int arr[n];
	j=n-1;
	printf("Enter %d integers.\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for (i=0;i<n/2;i++)
	{
		if(arr[i]!=arr[j])
		{
			f=1;
			break;
		}
		j--;
	}
	if (f==0)
	{
		printf("The array is a palindrome.\n");
	}
	else
	{
		printf("The array is not a palindrome.\n");
	}
       return 0;
}       
	

