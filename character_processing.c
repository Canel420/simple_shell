#include "shell.h"

void char_processing(char *buffer)
{
	char **tokens = split_strings(buffer, ' ');
	char *path = mini_paths(tokens[0]);
	int new;

	printf("This is the first token = %s\n", tokens[0]);
	printf("This is the second token = %s\n", tokens[1]);
	printf("This is the resulting path = %s\n", path);

	new = new_process(path, tokens);

	free(path);
	free(tokens);
}
