#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/* Prototypes */

char **split_strings(char *str, char delimiter);
int character_processing(char *buffer);


#endif
