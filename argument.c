#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "main.h"
#define STDIN stdin

/**
 *main - entry point
 *Description - Functions that handles command lines
 *@int - pointer to integer value
 *@i - value of interger
 *@char - pointer to the user input
 *
 *return - Always 0 (on success)
 */

void int(store2);
void int(i);
void char(c);
void argument(int, char);
int main(void)
{
char store[] = "User input";
int store2[] = "integer value";
size_t x = 0;
int i = 0;

const char *delimeter = "d";
char *store2[50] = {NULL};

printf("My string before tokenization is %s\n", store);
printf("My string after tokenization is \n");
printf("The value of x is: %lu\n", x);

store2[i] = strtok(store, delimeter);

printf("%s\n", store2[i]);

while (store2 != NULL)
{

store2[i] = strtok(NULL, delimeter);

printf("%s\n", store2[i]);
i++;

return (0);
}
}
