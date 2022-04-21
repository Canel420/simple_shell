#include "shell.h"

/**
 * free_dp - Function to free a double pointer array.
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