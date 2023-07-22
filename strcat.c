#include "main.h"

/**
 * my_strcat - a function that concatenates two given strings
 * @dest: the argument that holds the result
 * @src: the argument that is appended to the destination pointer.
 * Return: Always 0.
 */
char *my_strcat(char *dest, char *src)
{

	int i = 0;
	int g = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[g] != '\0')
	{
		dest[i] = src[g];
		g++;
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
