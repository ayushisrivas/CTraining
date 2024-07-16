
#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main()
{
	int fd[2];
	pid_t pid;
	char buf[20];
	ssize_t bytes_read;

	if(pipe(fd)<0)
	{
		perror("Error in creating pipe");
		exit(1);
	}

	if((pid=fork())<0)
	{
		perror("Forking error");
		exit(1);
	}
	else if(pid >0)
	{
		close(fd[0]);
		char *message="message from parent";
		if(write(fd[1],message,strlen(message)+1)!=strlen(message)+1)
		{
			perror("Write error");
			exit(1);
		}
		close(fd[1]);
	}
	else if(pid==0)
	{
		close(fd[1]);
		bytes_read=read(fd[0],buf,sizeof(buf));
		if(bytes_read==-1)
		{
			perror("No read");
			exit(1);
		}
		printf("The message is: %s\n",buf);
		close(fd[0]);
	}
	return 0;
}


