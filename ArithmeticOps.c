#include<stdio.h>
int main(){
	int a,b;
	printf("Enter two numbers to perform all arithmetic operations: ");
	scanf("%d%d", &a,&b);
	printf("\n");
	printf("The sum is : %d\n", a+b);
	printf("The difference is : %d\n", a-b);
	printf("The product is : %d\n", a*b);
	printf("The quotient is : %d\n", a/b);
	printf("The remainder is : %d\n", a%b);
	return 0;
}
