#include "shell.h"

char *mini_paths(char *command)
{
	char **mini_paths;
	const char *path = getenv("PATH");
        char *copy, *mini_search;
	int i, mini_len, cmd_len, path_len;

	path_len = strlen(path) + 1;
	copy = (char *)malloc(sizeof(char) * path_len);

	if (copy == NULL)
	{
		free(copy);
		printf("malloc failed\n");
	}

	strcpy(copy, path);

	mini_paths = split_strings(copy, ':');

        for (i = 0; mini_paths[i] != NULL; i++)
	{
		cmd_len = strlen(command);
		mini_len = strlen(mini_paths[i]);

		mini_search = malloc(sizeof(char) * (mini_len + cmd_len + 2));

		if (mini_search == NULL)
		{
			free(mini_search);
			perror("Error:");
			exit(98);
		}

		strcpy(mini_search, mini_paths[i]);
		mini_search[mini_len] = '/';
		strcpy(mini_search + mini_len + 1, command);
		mini_search[mini_len + cmd_len + 1] = '\0';

		if (access(mini_search, F_OK & X_OK) == -1)
		{
			free(mini_search);
			continue;
		}
		else
			break;
	}

	free(mini_paths);
	free(copy);

	return (mini_search);
}
