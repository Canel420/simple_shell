#include "shell.h"

/**
 * mini_paths - Function that finds the path of a given command.
 *
 * @command: Command to search in PATH.
 *
 * Description: This function call the PATH enviromental variable,
 * makes a copy of it, and tokenize each of the paths in there. Then
 * adds the given command and confirms if the commands exist.
 *
 * Return: The command of the path if it exist or null in case it doesn't.
 *
 */

char *mini_paths(char *command)
{
	unsigned int cmd_len, path_len;
	const char *path = getenv("PATH");
	char *copy, *token, *mini_search;

	cmd_len = _strlen(command);
	path_len = _strlen(path) + 1;

	copy = malloc(sizeof(char) * path_len);
	if (copy == NULL)
	{
		perror("Error in copy");
		return (NULL);
	}
	strcpy(copy, path);

	token = strtok(copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_len = _strlen(token);
		mini_search = malloc(sizeof(char) * (path_len + cmd_len + 2));
		if (mini_search == NULL)
		{
			perror("Error in malloc");
			return (NULL);
		}
		strcpy(mini_search, token);
	        mini_search[path_len] = '/';
		strcpy(mini_search + path_len + 1, command);
	        mini_search[path_len + cmd_len + 1] = '\0';

		if (access(mini_search, F_OK & X_OK) != 0)
		{
			free(mini_search);
		        mini_search = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(copy);
	return (mini_search);
}