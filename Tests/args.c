#include <stdio.h>

/**
 * main - Print all command line arguments
 *
 * @argc:argument count. Unused
 * @argv: Reference to array of arguments.
 *
 * Return: Always 0.
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	int i;

	for (i = 1; argv[i] != NULL; i++)
		printf("%s\n", argv[i]);
	return (0);
}
