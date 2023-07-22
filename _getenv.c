#include "main.h"
/**
 * _getenv - a function that gets a specific envirnoment
 * @name: the pointer to a string that holds the
 * name of the environment
 *
 * Return: the pointer to the gotten environment
 */
char *_getenv(const char *name)
{
	size_t count;
	int i;

	if (name == NULL)
		return (NULL);
	if (*name == '\0')
		return (NULL);
	count = my_strlen((char *)(name));
	i = 0;
	while (environ[i] != NULL)
	{
		if (my_strncmp(environ[i], (char *)(name), count) == 0 &&
		environ[i][count] == '=')
		{
			return (&(environ[i][count + 1]));
		}
		i++;
	}
	return (NULL);
}
