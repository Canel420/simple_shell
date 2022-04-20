#include "shell.h"

char *env_copy(void)
{
	const char *path = getenv("PATH");
	int path_len;
	char *copy = NULL;

        path_len = strlen(path) + 1;

	copy = malloc(sizeof(char) * path_len);
	if (copy == NULL)
	{
		perror("Error in copy");
		return (NULL);
	}
	strcpy(copy, path);

	return (copy);
}
