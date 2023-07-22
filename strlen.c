#include "main.h"

/**
 * my_strlen - check the code
 * @s: parameter passed of type char.
 * Return: Always 0.
 */
int my_strlen(char *s)
{
	int len;
	char *l =  s;

	len = 0;
	while (*l != '\0')
	{
	l++;
	len++;
	}
	return (len);
}

