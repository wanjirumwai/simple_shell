#include <stdio.h>
#include <stddef.h>

#define STDIN stdin

int main(void)
{
char store[] = "User input";
size_t x = 0;
int i = 0;

const char *delimeter = "d";

printf("My string before tokenization is %s\n", store);
printf("My string after tokenization is \n");

char *store2[50] = {};
store2[i] = strtok(store, delimeter);

printf("%s\n", store2[i]);

while (store2 != NULL)
{

//store2[] = NULL;
store2[i] = strtok(NULL, delimeter);

printf("%s\n", store2[i]);
i++;
}
