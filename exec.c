#include "main.h"
/**
 * execute - function that executes a process in the shell process
 * @av: a double pointer to the string
 *
 * Return: `-1` while the function fails
 */
int execute(char **av)
{
	char *input_cmd = NULL;
	int n;
/**	char *env[] = {"PATH=/usr/bin",
	"HOME=/path/to/user/home",
	"TERM=xterm",
	NULL};
*/	if (av == NULL)
		return (-1);
	input_cmd = get_path(av);
	if (input_cmd != NULL)
	{
		setenv("LC_COLLATE", "C", 1);
		n = execve(input_cmd, av, environ);
		if (n == -1)
		{
			free(input_cmd);
			perror("Error");
			return (-1);
		}
		free(input_cmd);
		return (0);
	}
	else
		perror("Error");
	return (-1);
}
