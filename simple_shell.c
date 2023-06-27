#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

/**
 * Handle_signal - This Function informs the compiler of its existence
 * @int - Pointer to the integer value
 *
 * Return - 0 on success
 */

extern char **environ;

void handle_signal(int signal);
{

void handle_signal(int signal){
    if (signal == SIGINT) {
        printf("\n");
        printf("simple_shell$ ");
        fflush(stdout);
    }
/**
 * main - program entry point
 *
 * Return - Always 0 success.
 */

int main(void) 

{
    char c[1024];
    int i;

    signal(SIGINT, handle_signal); 

    while (1) {
        printf("simple_shell$ ");
        if (fgets(c, sizeof(c), stdin) == NULL) {
            printf("\n");
            break;
        }

        c[strcspn(c, "\n")] = '\0';

        if (strlen(c) == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            
            char *args[] = {c, NULL};
            if (execve(c, args, environ) == -1) {
                perror("Execution error of command");
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(pid, &i, 0);
        }
    }

    return 0;
}
