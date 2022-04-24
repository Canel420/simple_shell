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
	char *token, *mini_search, *env = _getenv("PATH");

	cmd_len = _strlen(command);

	if (access(command, X_OK) == 0)
	{
		printf("command has access");
		return (NULL);
	}

	token = strtok(env, ":");
	if (token == NULL)
		token = strtok(NULL, ":");

	while (token != NULL)
	{
		path_len = _strlen(token);
		mini_search = malloc(sizeof(char) * (path_len + cmd_len) + 2);
		if (mini_search == NULL)
		{
			perror("sh: Error");
			return (NULL);
		}
		_strcpy(mini_search, token);
		mini_search[path_len] = '/';
		_strcpy(mini_search + path_len + 1, command);
		mini_search[path_len + cmd_len + 1] = '\0';

		if (access(mini_search, X_OK) != 0)
		{
			free(mini_search);
			mini_search = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(env);
	return (mini_search);
}
