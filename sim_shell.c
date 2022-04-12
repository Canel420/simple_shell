#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int character_processing(char *buffer)
{
	int hold_error;
	char *const argv[] = {"/bin/ls", NULL};

	hold_error = execve(buffer, argv, NULL);
	if (hold_error == -1)
	{
		perror("Error");
		return(-1);
	}
	return (0);
}

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
			/*char_count = strlen(buffer);*/
			/*write(1, buffer, char_count);*/
			free(buffer);

			buffer = NULL;
			char_count = 0;
			write(1, "\n", 1);
		}
	}
	return (0);
}
