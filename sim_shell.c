#include "shell.h"

/**
 * _isatty - Function to check fir interactive mode and print prompt.
 *
 * Description: Determines if initiation of the shell is in interactive mode
 * and displays a prompt.
 *
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
}

/**
 * main - SHELL call
 *
 * Return: Call to recursive SHELL.
 *
 */

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
		tokens = tokenizer(buffer, " \n");

		if (!buffer)
			return (0);
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free_dp(tokens);
			shell_exit();
		}
		if (_strcmp(tokens[0], "env") == 0)
		{
			shell_env();
		}
		path = mini_paths(tokens[0]);
		new_process(path, tokens);

		free(path);
		free_dp(tokens);
		free(buffer);
		buffer = NULL;
		char_count = 0;
	}
	write(1, "\n", 1);

	return (0);
}
