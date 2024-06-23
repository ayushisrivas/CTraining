#include<stdio.h>
int main(){
	long int bin,dec=0;
	int n,m=1;
	printf("Enter the binary number to be converted to decimal: ");
	scanf("%ld",&bin);

	while(bin){
		n=bin%10;
		bin=bin/10;
		dec+=n*m;
	       m*=2;
	}
	printf("The decimal value is : %ld\n",dec);
	return 0;
}	
