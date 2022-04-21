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

char **tokenizer(char *buffer, const char *delimiter);
char *mini_paths(char *command);
int new_process(char *mini_path, char **tokens);
void char_processing(char **tokens, char *path);

char **env_copy(char **environ_copy, unsigned int environ_length);
char *_getenv(const char *name);

/* Helpers */

int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *str1, char *str2, unsigned int length);
char *_strcpy(char *dest, char *src);

/* built- ins */

void shell_exit(void);
void shell_env(void);

/* Free double pointer */

void free_dp(char **double_pointer);

#endif /* SHELL_H */
