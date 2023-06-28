#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define STDIN stdin

/**
 * main - Program entry point
 *
 * return - 0 on success, non zero value on error
 */

int main(void)
{
char store[] = "User input";
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
