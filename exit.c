#include "main.h"
/**
 * exit_but - Entry point
 * @res: argument
 * Return: nothing
 */
void exit_but(char **res)
{
	int status, i;

	if (res[1])
	{
		status = atoi(res[1]);
		for (i = 0; res[i] != NULL; i++)
		{
			free(res[i]);
			res[i] = NULL;
		}
		free(res);
		exit(status);
		}

	else
	{
		free(res[0]);
		res[0] = NULL;
		free(res);
		exit(0);
	}
}
