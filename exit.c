#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_CMD_LENGTH 100

/**
 * main - Entry Point
 *
 * Return: Always 0 (on success)
 *
 */

int main(void)
{
	char c[MAX_CMD_LENGTH];

	while (1)
	{
		write(STDOUT_FILENO, "Shell> ", 7);
		ssize_t read_bytes = read(STDIN_FILENO, c, MAX_CMD_LENGTH);

		if (read_bytes == -1)
		{
			perror("read");
			exit(1);
		}
		c[read_bytes - 1] = '\0';
		if (strcmp(c, "exit") == 0)
		{
			_exit(0);
		}

/**
 * _mychange - this function changes the current directory process
 * @info: Structure containing potential arguments.
 * Return: 0 on success
 */
int _mychange(info_t *)
{

	char **arg_array;

	arg_array = info->argv;
	_puts("call the process. confirm whether the process is called \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
