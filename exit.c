#include <stdlib.h>
#include "main.h"

/**
 * exit_but - function that exits a shell process
 * @res: a double pointer to a string
 *
 * Return: void.
 */
void exit_but(char **res)
{
	int n, i, len;

	if (res[1])
	{
		len = my_strlen(res[1]);
		n = my_atoi(res[1]);
		if (n)
		{
		for (i = 0; res[1][i] != '\0'; i++)
		{
			if (res[1][i] >= '0' && res[1][i] <= '9')
			{
				if (i == len - 1)
				{
					free(res[0]);
					free(res[1]);
					free(res);
					exit(n);
				}
				continue;
			}
			else
			{
				perror("error: exit takes only integer args");
				free(res[0]);
				free(res[1]);
				free(res);
				exit(2);
			}
		}
		}
	}

	else
	{
		free(res[0]);
		free(res);
		exit(2);
	}
}
