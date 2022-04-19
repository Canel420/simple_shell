#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t char_count = 0;
	char **tokens;

	while (write(1, "$ ", 2) && getline(&buffer, &char_count, stdin) != EOF)
	{

		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
		        return (-1);
		}
		else
		{
			tokens = split_strings(buffer, ' ');
			char_processing(tokens);

			free(buffer);
			buffer = NULL;
			char_count = 0;

		}
		free(tokens);
		write(1, "\n", 1);
	}
	return (0);
}
