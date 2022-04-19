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
	unsigned int cmd_len, path_len;
	const char *path = getenv("PATH");
	char *copy, *token, *mini_search;

	cmd_len = strlen(command);
	path_len = strlen(path) + 1;

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
		path_len = strlen(token);
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

int new_process(char *mini_path, char **tokens)
{
	pid_t process_id;
	int state, exe_state;
	char **envp = environ;

	if (mini_path == NULL)
	{
		perror("Error:");
		return (-1);
	}

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
	char str[] = "pwd";
	char **tokens = split_strings(str, ' ');
	char *path = mini_paths(tokens[0]);

	printf("This is the first token = %s\n", tokens[0]);
	printf("This is the resulting path = %s\n", path);

	new_process(path, tokens);

	free(path);
	free(tokens);

	return (0);
}
