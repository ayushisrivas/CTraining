#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 4096

int main() {
    int fd[2]; 
    pid_t pid;
    int fd_input, fd_output;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    if ((pid = fork()) == -1) 
    {
        perror("fork");
        exit(1);
    } 
    else if (pid > 0)
    {
        close(fd[0]);

       if ((fd_input = open("input.txt", O_RDONLY)) == -1) 
       {
            perror("open input.txt");
            exit(1);
       }

       while ((bytes_read = read(fd_input, buffer, BUFFER_SIZE)) > 0)
       {
            if (write(fd[1], buffer, bytes_read) != bytes_read) 
	    {
                perror("write to pipe");
                exit(1);
            }
        }

        close(fd[1]);
        close(fd_input);

        wait(NULL);
    } 
    else 
    { 
	    close(fd[1]);
	    if ((fd_output = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) 
	    {
            	perror("open output.txt");
            	exit(EXIT_FAILURE);
        }

        while ((bytes_read = read(fd[0], buffer, BUFFER_SIZE)) > 0) {
            if (write(fd_output, buffer, bytes_read) != bytes_read) {
                perror("write to output.txt");
                exit(1);
            }
        }

        close(fd[0]);
        close(fd_output);
        exit(0);
    }

    return 0;
}

