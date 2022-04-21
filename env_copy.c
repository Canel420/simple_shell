#include "shell.h"

/**
 * env_copy - Function that makes a copy of the enviromental variable.
 *
 * Description: Takes the enviromental variable PATH and makes a copy.
 *
 * Return: A pointer to the copy.
 *
 */

char *env_copy(void)
{
	const char *path = getenv("PATH");
	int path_len;
	char *copy = NULL;

	path_len = strlen(path) + 1;

	copy = malloc(sizeof(char) * path_len);
	if (copy == NULL)
	{
		perror("sh: Error");
		return (NULL);
	}
	strcpy(copy, path);
	return (copy);
}
