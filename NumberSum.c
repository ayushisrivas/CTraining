#include<stdio.h>
int main(){
	long long int a, sum=0,digit;

	printf("Enter the number: ");
	scanf(" %lld",&a);
	while(a)
	{
		digit = a%10;
		a=a/10;
		sum+=digit;
	}
	printf("The sum is : %lld\n", sum);
	return 0;
}

