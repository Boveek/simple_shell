#include "main.h"

/**
 * my_atoi - function that works like the builtin atoi
 * @s: the pointer to the string to be converted
 *
 * Return: the integer result
 */
int my_atoi(char *s)
{
	int i, x = 0, y = -1, z = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			y = y * -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			x = x * 10;
			x -= (s[i] - '0');
			z = 1;
		}
		else if (z == 1)
			break;
	}
	x = y * x;
	return (x);
}
