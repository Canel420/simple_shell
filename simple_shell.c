#include "shell.h"

/**
 * SHELL -Recursion function for calling a prompt
 *
 * @string: True condition to maintain the loop infinite.
 *
 * Description: Maintains and infinite loop while conditions are,
 * and not exit or EOF is given.
 *
 * Return: A calling to the same  SHELL to maintain recursion.
 */

int SHELL(char **string)
{
	size_t char_count = 0;
	char **tokens = NULL;
	char *path = NULL;

	if (!(*string))
		return (0);

	write(1, "$ ", 2);
	if (getline(&(*string), &char_count, stdin) != EOF)
	{
		if (strcmp((*string), "exit\n") == 0)
			shell_exit();
		if (strcmp((*string), "env\n") == 0)
			shell_env();
		else
		{
			tokens = tokenizer((*string), "\n ");
			path = mini_paths(tokens[0]);
			new_process(path, tokens);

			free(path);
			free_dp(tokens);
			free(*string);
			(*string) = "True";
		}
	}
	return (SHELL(string));
}


/**
 * main - SHELL call
 *
 * Return: Call to recursive SHELL.
 *
 */

int main(void)
{
	char *string = "True";

	return (SHELL(&string));
}
