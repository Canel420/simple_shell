#include "shell.h"

void _EOF(int init, char *buffer)
{
	(void)buffer;
	if (init == -1)
	{
		if (isatty(STDIN_FILENO))
		{
		        write(1, "\n", 1);
			free(buffer);
		}
		exit(0);
	}
}

void _isatty(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
}

int main(void)
{
	size_t init = 0;
	size_t char_count = 0;
	char *buffer = NULL;
	char **tokens = NULL;
	char *path = NULL;

	while (init != (size_t)EOF)
	{
		_isatty();

	        init = getline(&buffer, &char_count, stdin);
		if (!buffer)
			return (0);

	        _EOF(init, buffer);

		else
		{
			if (_strcmp(buffer, "exit\n") == 0)
				shell_exit();

			if (_strcmp(buffer, "env\n") == 0)
			{
				shell_env();
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
