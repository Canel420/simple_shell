#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t char_count = 0;

	while (write(1, "$ ", 2) && getline(&buffer, &char_count, stdin) != EOF)
	{
		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			return (1);
		}
		else
		{
			character_processing(buffer);
			free(buffer);

			buffer = NULL;
			char_count = 0;
			write(1, "\n", 1);
		}
	}
	return (0);
}
