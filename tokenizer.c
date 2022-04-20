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
	char *tokens_count = NULL, *tokens = NULL, *ptr = NULL, **ar = NULL;

	if (!(buffer) || !(delimiter))
		return (NULL);

        tokens_count = _strdup(buffer);
        tokens = _strdup(buffer);

	if (!(tokens_count) || !(tokens))
		return (NULL);

	ptr = strtok(tokens_count, delimiter);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ptr = strtok(NULL, delimiter);
	}

	ar = malloc(sizeof(char *) * (i + 1));
	if (ar == NULL)
		return (NULL);

	ptr = strtok(tokens, delimiter);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ar[i] = _strdup(ptr);
		ptr = strtok(NULL, delimiter);
	}

	ar[i] = NULL;
	free(tokens_count);
	free(tokens);
	return (ar);
}
