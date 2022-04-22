#include "shell.h"

/**
 * _getenv - Functions that gets an enviromental variable.
 *
 * @name: Pointer name to the environmental variable to retrieve.
 *
 * Description: Makes a copy of the enviromental variables saved in
 * environ extern variable, and returns a copy of the desire variable.
 *
 * Return: Pointer to desire enviromental variable.
 *
 */

char *_getenv(const char *name)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, i;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;

	environ_copy = NULL;
	environ_copy = env_copy(environ_copy, environ_length);

	length = _strlen((char *)name);
	i = 0;
	while (environ_copy[i] != NULL)
	{
		variable = environ_copy[i];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (value == NULL)
			{
				exit(3);
			}
			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				return (NULL);
			}
			path = strcpy(path, value);
			free_n_dp(environ_copy, environ_length);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * env_copy - Function that makes a copy of the enviromental variable.
 *
 * @environ_copy: Copy of the enviromental variables.
 * @environ_length: Length of the entire environment.
 *
 * Description: Makes a copy of the enviroment of the user.
 *
 * Return: A pointer to the copy.
 *
 */

char **env_copy(char **environ_copy, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	environ_copy = malloc(sizeof(char **) * (environ_length));
	if (environ_copy == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		environ_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (environ_copy[i] == NULL)
		{
			return (NULL);
		}
		_strcpy(environ_copy[i], environ[i]);
		i++;
	}

	return (environ_copy);
}
