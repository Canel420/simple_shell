#include "shell.h"

char **split_strings(char *buffer, char delimiter)
{
	char **tokens;
	char *token;
        int i = 0;

	tokens = malloc(sizeof(char) * 1024);
	if (tokens == NULL)
	{
		perror("Error:");
		free(tokens);
		exit(98);
	}

	token = strtok(buffer, &delimiter);

	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, &delimiter);
	}
	tokens[i] = NULL;
	free(tokens);
	return (tokens);
}

int character_processing(char *buffer)
{
	int hold_error;
	char **command = NULL;
	char delimiter = ' ';
	char *const argv[] = {"ls", NULL};

        command = split_strings(buffer, delimiter);

	hold_error = execve(command[0], argv, NULL);
	if (hold_error == -1)
	{
		perror("Error");
		return(-1);
	}
	return (0);
}
