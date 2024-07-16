
#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	int n =(int)argv[0];
	for(int i=0;i,n;i++)
	{
	int pid = fork();

	if(pid ==0)
		printf("Hello from child!\n");
	else
	{	
		wait();
		printf("Hello from parent!\n");
	}
	}
	return 0;
}
