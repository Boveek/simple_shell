#include "main.h"

/**
 * my_strdup - funtion thats duplicates string and allocates memory for it.
 * @str: the string passed to it.
 *
 * Return: the pointer to the duplicate string.
 */
char *my_strdup(char *str)
{
	char *dup;
	int h = my_strlen(str) + 1;

	if (str == NULL)
	{
		return (NULL);
	}

	dup = malloc(h * sizeof(char));

	if (dup == NULL)
		return (NULL);

	my_strcpy(dup, str);

return (dup);
}

