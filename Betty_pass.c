#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */

int main(void)
{
	char *message = "hello world\n";

	write(STDOUT_FILENO, message);

	return (0);
}
