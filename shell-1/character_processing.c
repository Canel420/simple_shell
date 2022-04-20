#include "shell.h"

void char_processing(char **tokens, char *path)
{

	if (_strcmp(tokens[0], "exit\n") == 0)
	{
		exit(3);
	}

	if (path != NULL)
	{
	        new_process(path, tokens);
	}
	else
	{
		perror("Error");
	}
}
