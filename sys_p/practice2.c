
#include<stdio.h>
#include<unistd.h>
int main()
{
	int n,pid;
	scanf("%d[^\n] ",&n);
	for(int i=0;i<n;i++)
	{
		pid = fork();

		if(pid ==0)
		{
			printf("\n%d: Hello from child %d, parent is %d\n",i,getpid(),getppid());
		//	exit(1);
		}
		else
		{	
			wait();
			printf("All children have terminated for parent %d\n",getpid());
		//	exit(1);
		}
	}
	return 0;
}
