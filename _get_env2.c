#include <stdio.h>
#include "main.h"

/**
 * _getenv2 - a function that print the enviroment of the current shell
 *
 * Return: void.
 */
void _getenv2(char **env)
{
	int i = 0;

	while (*env != NULL)
	{
		while ((*env)[i] != '\0')
		{
			if (write(1, &((*env)[i]), 1) == -1)
			{
				perror("Error");
				return;
			}
			
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		env++;
	}

}
