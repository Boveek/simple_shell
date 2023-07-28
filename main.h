#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

#define BUFF_SIZE 1024
#define PATH_BUF 100
extern char **environ;
int main(int argc, char *argv[]);
int execute(char **av);
char *_getenv(const char *name);
char *get_path(char **av);
char *my_strcpy(char *dest, char *src);
int my_strlen(char *s);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, size_t n);
char *my_strdup(char *str);
void _getenv2(char **env);
void _getenv3(char **env);
ssize_t _getline(char **buff, size_t *n);
void exit_but(char **res);
int my_atoi(char *s);
void cd(char *dir);
char *_strtok(char *str, const char dem);
int checkexec(char **av);
int get_path2(char *av);
int process(int argc, char *argv[]);
#endif
