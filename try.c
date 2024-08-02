#include<stdio.h>
#define MAX(a,b) a>b?a:b

int main(){
	int a=7,b=9,n;
	n=MAX((a++),(b++));
	printf("%d",n);
	printf("%d %d",a,b);
	return 0;
}
