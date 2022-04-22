#include "shell.h"

int main(void)
{
	size_t char_count = 0;
	char *buffer = NULL;
	char **tokens = NULL;
	char *path = NULL;


	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);

	while (getline(&buffer, &char_count, stdin) != EOF)
	{
		if (!buffer)
			return (0);

		if (_strcmp(buffer, "exit\n") == 0)
			shell_exit();
		else
		{
			if (_strcmp(buffer, "env\n") == 0)
			{
				shell_env();
				free(buffer);
				buffer = NULL;
				char_count = 0;
			}

			tokens = tokenizer(buffer, "\n ");
			path = mini_paths(tokens[0]);
			new_process(path, tokens);

			free(path);
			free_dp(tokens);
			free(buffer);
			buffer = NULL;
			char_count = 0;
		}
	}
	write(1, "\n", 1);

	return (0);
}
