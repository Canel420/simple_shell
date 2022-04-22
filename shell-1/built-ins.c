#include "shell.h"

/**
 * shell_exit - Function to exit shell
 *
 * Description: Exits shell on call.
 *
 */

void shell_exit(void)
{
	exit(0);
}

/**
 * shell_env - Function to print the env.
 *
 * Description: Copy all the elements in the enviromental PATH variable
 * and prints it on standar output.
 *
 */

void shell_env(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
