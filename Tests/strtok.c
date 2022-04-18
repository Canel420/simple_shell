#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *split_str(char *buffer, char delimiter)
{
	char ptr[1024];
	int i = 0;

        ptr[i] = strtok(buffer, &delimiter);

	while (ptr[i] != NULL)
	{
		ptr[i] = strtok(NULL, &delimiter);
	}
	return (ptr);
}

int main()
{
	char *buff = "This is a string";
	char delim = ' ';
	char **arr;
	int i;

	arr = split_str(buff, delim);

	i = 0;

	while (*arr[i])
	{
		printf("%d\n", *arr[i]);
		i++;
	}
	return (0);
}
