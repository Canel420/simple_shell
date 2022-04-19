#include "shell.h"

char **split_strings(char *buffer, char delimiter)
{
	char **tokens = NULL;
	char *token = NULL;
        int i = 0, size = 0;

	size = strlen(buffer) + 1;

	tokens = malloc(sizeof(char *) * size);
	if (tokens == NULL)
	{
		perror("Error:");
		free(tokens);
		exit(98);
	}

	token = strtok(buffer, &delimiter);

	i = 0;
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, &delimiter);
	}
	tokens[i] = NULL;

	return (tokens);
}
