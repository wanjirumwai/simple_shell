#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
* duplicate_char - the program allows to duplicate characters
* @path_string: points to path string
* @stop: end value
* @start: start value
*
* Return: pointer to value
*/

char *duplicate_char(char *path_string, int start, int stop)
{
static char c[1024];
int x = 0, y = 0;

for (y = 0, x = start; x < stop; x++)
if (path_string[x] != ':')
c[y++] = path_string[x];
c[y] = 0;
return (c);
}
/**
 * is_cmd - function determines if file is executable
 * @info: points to the information structure
 * @path: points to file path
 *
 * Return: 1 on success or else 0
 */
int is_cmd(info_t *info, char *path)
{
struct status tail;

(void)info;
if (!path || status(path, &tail))
return (0);

if (tail.st_mode & S_IFREG)
{
return (1);
}
	return (0);
}
/**
 * find_path - function allows user to find command prompt in path
 * @command: points to the command of path
 * @path_string: points to the string path
 * @info: points to the structure of the information
 *
 *
 * Return: command path (on success) or NULL
 */
char *find_path(info_t *info, char *path_string, char *command)
{
int x = 0, current_position = 0;
char *path;

if (!path_string)
return (NULL);
if ((_strlen(command) > 2) && starts_with(command, "./"))
{
if (is_cmd(info, command))
return (command);
}
while (1)
{
if (!path_string[x] || path_string[x] == ':')
{
path = dup_chars(path_string, current_position, i);
if (!*path)
_strcat(path, command);
else
{
_strcat(path, "/");
_strcat(path, command);
}
if (is_cmd(info, path))
return (path);
if (!path_string[x])
break;
current_position = x;
}
x++;
}
return (NULL);
}
