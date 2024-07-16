#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main()
{
	int fd[2];
	pid_t pid;
	char buf[20];

	if(pipe(fd)<0)
	{
		printf("Error in creating pipe");
		exit(1);
	}

	if((pid=fork())<0)
	{
		printf("Forking error");
		exit(1);
	}
	else if(pid >0)
	{
		close(fd[0]);
		char *message="message from parent";
		write(fd[1],message,strlen(message)+1);
		close(fd[1]);
	}
	else if(pid==0)
	{
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("The message is: %s\n",buf);
		close(fd[0]);
	}
	return 0;
}


