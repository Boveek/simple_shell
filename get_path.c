#include "main.h"
/**
 * get_path - the function that gets path of a file
 * @av: double pointer to a string holding the name of the file
 *
 * Return: a pointer to the corresponding path name
 */
char *get_path(char **av)
{
	char *com_path, *com_path_copy, *command, *actual_path, *splited;
	int num, dir_len;
	struct stat buf;

	com_path = getenv("PATH");
	if (com_path)
	{
	com_path_copy = my_strdup(com_path);
	if (com_path_copy)
	{
	command = av[0], num = my_strlen(command);
	splited = _strtok(com_path_copy, ':');
	while (splited != NULL)
	{
		dir_len = my_strlen(splited);
		actual_path = malloc(num + dir_len + 2);
		if (actual_path)
		{
		my_strcpy(actual_path, splited), my_strcat(actual_path, "/");
		my_strcat(actual_path, command), my_strcat(actual_path, "\0");
		if (stat(actual_path, &buf) == 0)
		{
			free(com_path_copy);
			return (actual_path);
		}
		else
		{
			free(actual_path);
			splited = _strtok(NULL, ':');
		}}
		else
		{
			free(com_path_copy);
			return (NULL);
		}
	}
	free(com_path_copy);
	}}
	return (NULL);
}
