
#include<stdio.h>
#include<string.h>
#include<unistd.h>

void rev(char *str)
{
	int n =strlen(str);
	for(int i=0;i<n;i++)
	{
		str[i]=toupper(str[i]);
	}
}

int main()
{
	int fd1[2],fd2[2];
	pid_t pid;
	char buf[20];

	if(pipe(fd1)<0 || pipe(fd2)<0)
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
		close(fd1[0]);
		close(fd2[1]);
		char *message="message from parent";
		write(fd1[1],message,strlen(message)+1);
		close(fd1[1]);
		wait();
		read(fd2[0],buf,sizeof(buf));
		printf("The updated string is: %s\n",buf);
		close(fd2[0]);

	}
	else if(pid==0)
	{
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0],buf,sizeof(buf));
		printf("The recieved string is: %s\n",buf);
		rev(buf);
		close(fd1[0]);
		write(fd2[1],buf,strlen(buf)+1);
		close(fd2[1]);
		
	}
	return 0;
}


