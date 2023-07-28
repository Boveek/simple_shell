#include "main.h"
#include <stdbool.h>
/**
 * main - This is the program entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *input_ptr = NULL, *splited, *input_ptr_copy = NULL, *path_get, /*dol[3] = "$ ",*/ *setev = "setenv", **ev, *err;
	size_t t = 0;
	char **env = environ;
	ssize_t line_count;
	int i, p, num_splited = 0, /*bufflen,*/ status, waitget, result;
	char *v = "exit", *e = "env", *chd = "cd", /*buff[1024],*/ prompt[15] = "Simple_shell:$ ", /*promptbuf[1200],*/ *unenv = "unsetenv";
	bool pipe_in = false;

	pid_t pq;

	(void)argc;

	err = argv[0];
	while (1 && !pipe_in)
	{
		result = fflush(stdout);
		if (result != 0)
		{
			perror("Error (flushing)");
			return (-1);
		}
		if (isatty(STDIN_FILENO) == 1)
		{
		/*getcwd(buff, sizeof(buff));
		bufflen = my_strlen(buff);
		my_strcpy(promptbuf, prompt);
		my_strcpy(promptbuf + 13, buff);
		my_strcpy(promptbuf + 13 + bufflen, dol);*/
		write(STDOUT_FILENO, prompt, my_strlen(prompt));
		fflush(stdout);
		}
		else
		{
			pipe_in = true;
		}
		line_count = getline(&input_ptr, &t, stdin);
		if (line_count == -1)
		{
			input_ptr = NULL;
			return (-1);
		}
		if (line_count <= 1)
		{
			input_ptr = NULL;
			continue;
		}
		input_ptr[line_count - 1] = '\0';
		input_ptr_copy = strdup(input_ptr);
		if (input_ptr_copy == NULL)
			return (-1);
		splited = _strtok(input_ptr, ' ');
		if (splited == NULL)
		{
			free(input_ptr_copy);
			free(input_ptr);
			return (-1);
		}
		while (splited != NULL)
		{
			num_splited++;
			splited = _strtok(NULL, ' ');
		}
		num_splited++;
		ev = malloc(sizeof(char *) * num_splited);
		if (ev == NULL)
		{
			free(ev);
			return(-1);
		}
		splited = _strtok(input_ptr_copy, ' ');
		for (i = 0; splited != NULL; i++)
		{
			ev[i] = malloc(sizeof(char) * (my_strlen(splited) + 1));
			if (ev[i] == NULL)
			{
				free(ev[i]);
				return (-1);
			}
			my_strcpy(ev[i], splited);
			splited = _strtok(NULL, ' ');
		}
		ev[i] = NULL;
		if ((my_strcmp(ev[0], v) == 0) && i <= 2)
		{
			free(input_ptr_copy);
			free(input_ptr);
			exit_but(ev);
		}
		if (my_strcmp(ev[0], setev) == 0)
		{
			if (ev[1] == NULL || ev[2] == NULL)
			{
				fprintf(stderr, "Add a Variable and value\n");
				free(ev[0]);
				free(ev[1]);
				free(ev);
				free(input_ptr_copy);
			/*	exit(EXIT_FAILURE);*/
				continue;
			}
			if (setenv(ev[1], ev[2], 1) == -1)
			{
				fprintf(stderr, "Failed\n");
				exit(EXIT_FAILURE);
			}
			free(ev[0]);
			free(ev[1]);
			free(ev);
			free(input_ptr_copy);
			continue;
		}
		if (my_strcmp(ev[0], unenv) == 0)
		{
			if (ev[1] == NULL)
			{
				fprintf(stderr, "Add a Variable\n");
				free(ev[0]);
				free(ev[1]);
				free(ev);
				free(input_ptr_copy);
				continue;
			}
			if (unsetenv(ev[1]) == -1)
			{
				perror("Error: Variable not found");
				exit(EXIT_FAILURE);
			}
			free(ev[0]);
			free(ev[1]);
			free(ev);
			free(input_ptr_copy);
			continue;
		}
		if (my_strcmp(ev[0], e) == 0)
		{
			_getenv2(env);
			free(ev[0]);
			free(ev);
			free(input_ptr_copy);
			continue;
		}
		if (my_strcmp(ev[0], chd) == 0)
		{
			cd(ev[1]);
			if (ev[1])
				free(ev[1]);
			free(ev[0]);
			free(ev);
			free(input_ptr_copy);
			continue;
		}
		path_get = get_path(ev);
		if (path_get != NULL)
		{
			pq = fork();
			if (pq == -1)
			{
				perror("Error(fork)");
				free(path_get);
				return (-1);
			}
			if (pq == 0)
			{
				fflush(stdout);
				p = execute(ev);
				if (p == -1)
				{
					free(path_get);
					perror("Error");
					return (-1);
				}
				free(path_get);
				exit(0);
			}
			if ((waitget = wait(&status)) == -1)
                        {
                    	    perror("Error (wait)");
			    free(path_get);
                            return (-1);
                        }
			free(path_get);
		}
		else
		{
			if (access(ev[0], F_OK) == 0)
			{
				pq = fork();
				if (pq == -1)
				{
					perror("Error(fork)");
					return (-1);
				}
				if (pq == 0)
				{
					fflush(stdout);
					setenv("LC_COLLATE", "C", 1);
					if (execve(ev[0], ev, environ) == -1)
					{
						perror("execve: ");
						free(path_get);
						return (-1);
					}
					exit(0);
				}
				if (waitpid(pq, &status, 0) == -1)
				{
					perror("Error (wait)");
					return (-1);
				}
			}
			else
			{
				/**fprintf(stderr, "%s: 1: %s: not found\n", err, ev[0]);*/
				fprintf(stderr, "%s: No such file or directory\n", err);
			}
		}
		for (i = 0; ev[i] != NULL; i++)
			free(ev[i]);
		free(ev);
		free(input_ptr_copy);
		num_splited = 0;
		free(input_ptr);
		input_ptr = NULL;
		input_ptr_copy = NULL;
		fflush(stdout);
	}
	return (0);
}
