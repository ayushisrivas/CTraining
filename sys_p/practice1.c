#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid = fork();

	if(pid ==0)
		printf("Hello from child!\n");
	else
	{	
		wait();
		printf("Hello from parent!\n");
	}
	return 0;
}
