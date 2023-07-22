#include "main.h"

/**
 * _strtok - a function that tokenize a string
 * @str: pointer to the string
 * @dem: the delimiter character
 * Return: pointer to the substrings
 */
char *_strtok(char *str, const char dem)
{
	static char *next = NULL;
	char *current;

	if (str != NULL)
		next = str;
	if (next == NULL)
		return (NULL);
	while (*next == ' ')
	{
		next++;
	}
	if (*next == '\0')
		return (NULL);
	current = next;
	while (*next)
	{
		if (*next == dem)
		{
			*next = '\0';
			next++;
			return (current);
		}
		next++;
	}
	next = NULL;

	return (current);
}
