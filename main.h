#ifndef MAIN_H
#define MAIN_H

#include <main.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void handle_signal(int signal_number);
int main(void);
char *_strchr(char *, char);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
void argument(int i, char c);
void fork_cmd(info_t *);
char *find_path(info_t *info, char *path_string, char *command);
int is_cmd(info_t *info, char *path);
char *_strncat(char *, char *, int);
char *find_path(info_t *, char *, char);
void find_cmd(info_t *);
char *_strncpy(char *, char *, int);
char *duplicate_char(char *, int, int);


#endif
