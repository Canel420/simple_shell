#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t char_count = 0;
	char **tokens = NULL;
	char *path = NULL;

	while (write(1, "$ ", 2) && getline(&buffer, &char_count, stdin) != EOF)
	{

		tokens = split_strings(buffer, ' ');
		path = mini_paths(tokens[0]);

		char_processing(tokens, path);


		free(tokens);
		free(path);

		free(buffer);
		buffer = NULL;
		char_count = 0;
		write(1, "\n", 1);
	}
	return (0);
}
