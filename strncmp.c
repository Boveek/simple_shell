#include "main.h"

/**
 * my_strncmp - function that compares two strings until
 * a certain number of bytes is reached
 * @s1: pointer to the first string
 * @s2: pointer to the second sting
 * @n: the nth position to be compared
 * Return: 0 if it suceed
 */
int my_strncmp(char *s1, char *s2, size_t n)
{
	size_t g;
	int diff;

	g = 0;

	while ((s1[g] != '\0' || s2[g] != '\0') && g < n)
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
