#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	example_basic_pipe(void)
{
	int			pipefd[2];
	pid_t		pid;
	char		buf;
	const char	*message;

	message = "Hello from parent process!\n";
	printf("=== Example 1: Basic Pipe Usage ===\n");
	// Create the pipe
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return ;
	}
	printf("Pipe created successfully. Read fd: %d, Write fd: %d\n", pipefd[0],
			pipefd[1]);
	// Create child process
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(pipefd[0]);
		close(pipefd[1]);
		return ;
	}
	if (pid == 0)
	{
		// Child process reads from the pipe
		close(pipefd[1]); // Close unused write end
		printf("Child: Reading from pipe (fd %d)...\n", pipefd[0]);
		// Read and print data from the pipe, one character at a time
		printf("Child: Received: \"");
		while (read(pipefd[0], &buf, 1) > 0)
			printf("%c", buf);
		printf("\"\n");
		close(pipefd[0]); // Close read end
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Parent process writes to the pipe
		close(pipefd[0]); // Close unused read end
		printf("Parent: Writing to pipe (fd %d)...\n", pipefd[1]);
		printf("Parent: Sending message: \"%s\"\n", message);
		// Write the message to the pipe
		write(pipefd[1], message, strlen(message));
		close(pipefd[1]); // Close write end - signals EOF to the reader
		// Wait for child to complete
		wait(NULL);
		printf("Parent: Child has finished reading.\n");
	}
	printf("\n");
}

int	main(void)
{
	example_basic_pipe();
	return (0);
}
