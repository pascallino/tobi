#include "hsh.h"
void execute(char **args);
/**
 *  exececute - ======
 *  @command:  =======
 */
void execute(char **args)
{
	int pid;
	int exit_status;

	tobi1.errnum;
	pid  = fork();

	if (pid == 0)
	{
		if (strcmp(args[0], "echo") == 0)
		{
			execve("/bin/echo", args, environ);
		}
		else if (strcmp(args[0], "ls") == 0)
		{
			execve("/bin/ls", args, environ);
		}
		else
		{
			execve(args[0], args, environ);
		}
		_stdout(tobi1.app_name, 2);
		_stdout(": ", 2);
		putchar_number(tobi1.errnum);
		_stdout(": ", 2);/*./hsh: 1: qwerty: not found*/
		_stdout(args[0], 2);
		_stdout(": not found\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status  != 0 && (!isatty(STDIN_FILENO) && !(tobi1.colon == 1)))
			{
				exit(exit_status);
			}
		}
	}
}
