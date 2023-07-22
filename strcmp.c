#include "main.h"

/**
 * my_strcmp - function that compare two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: 0 if they are the same
 */
int my_strcmp(char *s1, char *s2)
{
	size_t g;
	int diff;

	g = 0;

	while ((s1[g] != '\0' || s2[g] != '\0'))
	{
	if (s1[g] != s2[g])
	{
		diff = s1[g] - s2[g];
		return (diff);
	}
	g++;
	}
	return (0);
}
