#include "shell.h"

/**
 * _strlen - Function that returns the length of a string.
 *
 * @s: Pointer to a string.
 *
 * Description: Takes a pointer to a character of a string and count
 * the characters until it reach '\0' character.
 *
 * Return: The count of the characters from a given string.
 */

int _strlen(const char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strdup - Duplicate a given string.
 *
 * @str: Pointer the string to duplicate.
 *
 * Description: Duplicate the string copying the given string to
 * a malloc memory space.
 *
 * Return: Pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	char *dupli = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i])
		i++;

	dupli = malloc(sizeof(char) * (i + 1));
	if (dupli == NULL)
		return (NULL);

	i = 0;
	while (str[i])
	{
		dupli[i] = str[i];
		i++;
	}

	dupli[i] = '\0';

	return (dupli);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: Pointer to a string.
 * @s2: Pointer to another string.
 *
 * Description: Takes to string pointers and compares characters
 * one by one.
 *
 * Return: 0 if characters aare equal, > 0 if left string has bigger Ascii
 * value and < 0 if rigth string has bigger Ascii value.
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0, count;

	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] == s2[a])
		{
			count = 0;
		}
		else
		{
			count = s1[a] - s2[a];
			break;
		}
		a++;
	}
	return (count);
}
