#include "shell.h"

/**
 * tokenizer - Takes a string to tokenize accordign to a delimiter.
 *
 * @buffer: String to tokenize.
 * @delimiter: Delimiter to make the tokens.
 *
 * Description: Takes a string and count the amount of tokens to make
 * according to delimiter, then save each token as element of an array.
 *
 * Return: Pointer to array of tokens
 */

char **tokenizer(char *buffer, const char *delimiter)
{
	int i = 0;
	char *str_1 = NULL, *str_2 = NULL, *ptr = NULL, **ar = NULL;

	if (!(buffer) || !(delimiter))
		return (NULL);

	str_1 = strdup(buffer);
	str_2 = strdup(buffer);
	if (!(str_1) || !(str_2))
		return (NULL);

	ptr = strtok(str_1, delimiter);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ptr = strtok(NULL, delimiter);
	}

	ar = malloc(sizeof(char *) * (i + 1));
	if (ar == NULL)
		return (NULL);

	ptr = strtok(str_2, delimiter);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ar[i] = strdup(ptr);
		ptr = strtok(NULL, delimiter);
	}

	ar[i] = NULL;
	free(str_1);
	free(str_2);
	return (ar);
}
