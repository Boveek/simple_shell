#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * _getline - function thats gets an input provided through the STDIN.
 * @buff: the double pointer to the buffer that holds the string
 * @n: the pointer to an integer
 *
 * Return: the number of character read.
 */
ssize_t _getline(char **buff, size_t *n)
{
	ssize_t fd;
	static char buffer[BUFF_SIZE];
	size_t size;

	if (n == NULL)
		return (-1);
	n = &size;

	fd = read(STDIN_FILENO, buffer, BUFF_SIZE);
	if (fd == -1)
	{
		perror("Error");
		return (-1);
	}
	*buff = buffer;

	return (fd);
}
