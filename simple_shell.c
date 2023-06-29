#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <main.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 *main - program entry point
 *@handle_signal - This Function informs the compiler of its existence
 *@signal_number - points to the handling number set out by the function
 *@int - points to the integer value
 *@signal - points to the signal value
 * Return - Always 0 success.
 */

void handle_signal(int signal_number)
{
	if (signal_number == SIGINT)
	{
		printf("\n");
		printf("simple_shell$ ");
		printf("Received signal: %d\n", signal_number);
		fflush(stdout);
	}
}

int main(void)
{
	char c[BUFFER_SIZE];
	int i = 0;
	pid_t pid;

	signal(SIGINT, handle_signal);

	while (1)
	{
		printf("simple_shell$ ");
		if (fgets(c, sizeof(c), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		c[strcspn(c, "\n")] = '\0';
		if (strlen(c) == 0)

		{
			continue;
		}

		pid = fork();
		if (pid < 0)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = {c, NULL};
			if (execve(c, args, NULL) == -1)
			{
				perror("Execution error of command");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, &i, 0);
			}
		}
		
		return (0);
	}
