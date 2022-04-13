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

int _strlen(char *s)
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
 * _strcpy - Copies the string pointed to by src.
 *
 * @dest: Pointer the copied array.
 * @src: Pointer to string to be copied.
 *
 * Description: Copies the string pointed to by src to
 * the buffer pointed to by dest.
 *
 * Return: The copied string.
 */

char *_strcpy(char *dest, char *src)
{
	char *sthg = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (sthg);
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
