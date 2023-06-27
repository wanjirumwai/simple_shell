#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * Handle_signal - This Function informs the complier of its exitence
 * @int - Pointer to the interger value
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

int main(void) 

{
    char command[1024];
    int status;

    signal(SIGINT, handle_signal); // Handle Ctrl+C interrupt signal

    while (1) {
        printf("simple_shell$ ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            char *args[] = {command, NULL};
            if (execve(command, args, environ) == -1) {
                perror("Command execution error");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
