#include<stdio.h>

int main(){
	int n;
	float f,c;
	printf("***Temperature calculator***\n");

	printf("-MENU\n");
	printf("1. Fahrenheit to Celsius\n");
	printf("2. Celsius to Fahrenheit\n");



	printf("Enter your choice: ");
	scanf("%d",&n);

	if(n==1){
		printf("Enter temperature in Fahrenheit: ");
		scanf("%f",&f);
		c= (f-32) *5 /9;
		printf("The temperature in Celsius is : %f", c);

	}
	else if(n==2){

		printf("Enter temperature in Celsius: ");

		scanf("%f",&c);
		f=(c*9/5)+32;
		printf("The temperature in Fahrenheit is : %f", f);
	}
	else
		printf("Wrong input");
	return 0;
}
