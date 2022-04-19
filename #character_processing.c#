#include "shell.h"

void char_processing(char **tokens)
{
	char *path = mini_paths(tokens[0]);
	printf("This is the path = %s\n", path);

	if (path != NULL)
	{
	        new_process(path, tokens);
	}
	else
	{
		perror("Error");
	}

	free(path);
}
