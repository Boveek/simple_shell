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
	char *pwd, pwd_buff[PATH_BUF];

	if (dir == NULL || strcmp(dir, "$HOME") == 0)
	{
		chdir("/root");
		return;
	}
	if (my_strlen(dir) == 1 && dir[0] == '-')
	{
		pwd = _getenv("OLDPWD");
		if (pwd)
		{
			cnt = chdir((const char *)(pwd));
			if (cnt != 0)
			{
				perror("Error");
				return;
			}
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(pwd_buff, sizeof(pwd_buff)), 1);
		}
		write(1, _getenv("PWD"), my_strlen(_getenv("PWD")));
		write(1, "\n", 1);
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", getcwd(pwd_buff, sizeof(pwd_buff)), 1);
		return;
	}
	else
	{
		cnt = chdir((const char *)(dir));
		if (cnt != 0)
		{
			perror("Error");
			return;
		}
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", getcwd(pwd_buff, sizeof(pwd_buff)), 1);
	}}
