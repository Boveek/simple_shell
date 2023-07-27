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
	int status;

	if (res[1])
	{
		status = atoi(res[1]);
		exit(status);
	}

	else
		exit(0);
}
