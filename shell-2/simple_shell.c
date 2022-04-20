#include "shell.h"

int SHELL(char **string)
{
	if (!(*string))
		return (0);
	else
	{
		size_t char_count = 0;
		char **tokens = NULL;
		char *path = NULL;

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
				printf("first token = %s\n", tokens[0]);
				path = mini_paths(tokens[0]);
				printf("This is the resulting path = %s\n", path);
				new_process(path, tokens);

				free(path);
				free(tokens);
				free(*string);
				(*string) = "True";
			}
		}

		return (SHELL(string));
	}
}

int main(void)
{
	char *string = "True";
	return (SHELL(&string));
}
