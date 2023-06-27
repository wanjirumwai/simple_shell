#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define STDIN stdin

/**
 *main - program entry point
 *@handle_signal - This Function informs the compiler of its existence
 *@signal - points to the handling number set out by the function
 *
 * Return - Always 0 success.
 */

extern char **environ;
void handle_signal(int signal);
signal(SIGINT, handle_signal);


void handle_signal(int signal)

if (signal == SIGINT)
{
printf("\n");
printf("simple_shell$ ");
fflush(stdout);
}

int main(void)
{
char c[1024];
int i;

signal(SIGINT, handle_signal);

while (1)
{
printf("simple_shell$ ");
if (fgets(c, sizeof(c), STDIN) == NULL)
{
printf("\n");
break;
}

c[strcspn(c, "\n")] = '\0';
if (strlen(c) == 0)
{
continue;
}

pid_t pid = fork();
if (pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char *args[] = {c, NULL};
if (execve(c, args, STDIN) == -1)
{
perror("Execution error of command");
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &i, 0);
}

return 0;
}
}
