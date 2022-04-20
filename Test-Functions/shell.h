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

extern char **environ;

char **split_strings(char *buffer, char delimiter);
char *mini_paths(char *command);
int new_process(char *mini_path, char **tokens);
void char_processing(char *buffer);

/* built- ins */
void shell_exit(void);
void shell_env(void);

#endif /* SHELL_H */
