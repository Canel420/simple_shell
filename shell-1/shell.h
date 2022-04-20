#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/* environment */

extern char **environ;

/* Shell functions */

char **split_strings(char *buffer, char delimiter);
char *mini_paths(char *command);
int new_process(char *mini_path, char **tokens);
void char_processing(char **tokens, char *path);
char *env_copy(void);
char **tokenizer(char *str, const char *delim);

/* Helpers */

int _strlen(const char *s);
int _strcmp(char *s1, char *s2);

#endif /* SHELL_H */
