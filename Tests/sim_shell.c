#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t char_count = 0;
	char **tokens = NULL;
	char *path = NULL;

	while (write(1, "$ ", 2) && getline(&buffer, &char_count, stdin) != EOF)
	{
		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			return (1);
		}
		else
		{
			tokens = split_strings(buffer, ' ');
			path = mini_paths(tokens[0]);
			printf("This is the resulting path = %s\n", path);

			free(buffer);
			buffer = NULL;
			char_count = 0;

		}
		free(tokens);
		free(path);
		write(1, "\n", 1);
	}
	return (0);
}
