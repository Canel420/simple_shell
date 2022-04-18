#include "shell.h"

char **split_strings(char *buffer, char delimiter)
{
	char **tokens;
	char *token;
        int i, size;

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

int new_process(char *mini_path, char **tokens)
{
	pid_t process_id;
	int state, exe_state;
	char **envp = environ;

	process_id = fork();

	if (process_id == -1)
	{
		perror("Error on fork: ");
		exit(98);
	}
	if (process_id == 0)
	{
		exe_state = execve(mini_path, tokens, envp);
		if (exe_state == -1)
			return (-1);
	}
	else
		wait(&state);

	return (0);
}

int main()
{
	char str[] = "mkdir testing-shell";
	char **tokens = split_strings(str, ' ');
	char *path = mini_paths(tokens[0]);
	int new;

	printf("This is first token = %s\n", tokens[0]);
	printf("This is the resulting path = %s\n", path);

	new = new_process(path, tokens);

	free(path);
	free(tokens);

	return(0);
}
