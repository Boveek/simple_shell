#include "main.h"

/**
 * cd - function that changes directory in a shell process
 * @dir: pointer to a string holding directory name or path.
 *
 * Return: void.
 */
void cd(char *dir)
{
	int cnt;
	char pwd_buff[PATH_BUF];

	if (dir == NULL || strcmp(dir, "$HOME") == 0)
	{
		cnt = chdir(getenv("HOME"));
	}


	else if (my_strlen(dir) == 1 && dir[0] == '-')
	{
		cnt = chdir(getenv("OLDPWD"));
		getcwd(pwd_buff, PATH_BUF);
		write(1, pwd_buff, strlen(pwd_buff));
		write(1, "\n", 1);
	}

	else
	{
		cnt = chdir((const char *)(dir));
	}

	if (cnt == -1)
	{
		perror("Error");
	}

	else if (cnt != -1)
	{
		getcwd(pwd_buff, PATH_BUF);
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", pwd_buff, 1);
	}
	
}



