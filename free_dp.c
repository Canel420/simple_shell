#include "shell.h"

/**
 * free_dp - Function to free a double pointer array.
 *
 * @double_pointer: Pointer to an array with malloc allocation over iteration.
 *
 * Description: Frees a double pointer that allocates memory on
 * each iteration when creating elements of the array.
 *
 */

void free_dp(char **double_pointer)
{
	int i = 0;

	if (double_pointer == NULL)
		return;
	while (double_pointer[i] != NULL)
	{
		free(double_pointer[i]);
		i++;
	}
	free(double_pointer);
}

/**
 * free_n_dp - Function to free a double pointer array until a given n
 *
 * @double_pointer: Pointer to an array with malloc allocation over iteration.
 * @n: length to free.
 *
 * Description: Frees a double pointer that allocates memory on
 * each iteration when creating elements of the array.
 *
 */

void free_n_dp(char **double_pointer, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		free(double_pointer[i]);
		i++;
	}
	free(double_pointer);
}
