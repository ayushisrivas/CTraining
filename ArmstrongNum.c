#include<math.h>
#include<stdio.h>
int main()
{
	int num,num2,n, a=0,b;
	printf("Enter the number: ");
	scanf("%d",&num);
	num2=num*num;
	n=num;
	while(num)
	{
		num=num/10;
		a+=1;
	}
	num=n;
	num2=0;
	while(num)
	{
		b=num%10;
		num=num/10;
		num2+=pow(b,a);

	}
	if(n==num2)
	{
		printf("It is an armstrong number!\n");
	}
	else
	{
		printf("It is not an armstrong number!\n");
	}
	return 0;
}

	
