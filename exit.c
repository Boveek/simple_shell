#include "main.h"

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
