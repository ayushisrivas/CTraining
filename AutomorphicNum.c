#include<stdio.h>
int main()
{
	int num,num2,n, a=1;
	printf("Enter the number: ");
	scanf("%d",&num);
	num2=num*num;
	n=num;
	while(num)
	{
		num=num/10;
		a*=10;
	}
	num2=num2%a;
	//printf("\n%d",num2);
	if(n==num2)
	{
		printf("It is an automorphic number!\n");
	}
	else
	{
		printf("It is not an automorphic number!\n");
	}
	return 0;
}

	
