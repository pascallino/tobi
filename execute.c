#include "hsh.h"
void execute(char **args, char *ech);
/**
 * execute - ======
 * @args:  =======
 * @ech: ============
 */
void execute(char **args, char *ech)
{
	int pid;
	int exit_status;

	if (tobi1.colon != 1)
		tobi1.errnum++;
	(void)ech;
	pid  = fork();

	if (pid == 0)
	{
		if (strcmp(args[0], "echo") == 0)
		{
			if (strcmp(ech, "$$") == 0)
			{
				putchar_number(getppid());
				_stdout("\n", 1);
				tobi1.exitcode = 0;
				free(tobi1.cmd);
				exit(0);
			}
			else if (strcmp(ech, "$?") == 0)
			{
				putchar_number(tobi1.exitcode);
				_stdout("\n", 1);
				tobi1.exitcode = 0;
				free(tobi1.cmd);
				exit(0);
			}
			else
			{
				execve("/bin/echo", args, environ);
			}
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
		tobi1.exitcode = 2;
		free(tobi1.cmd);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		tobi1.exitcode = 2;
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status == 1)
				tobi1.exitcode = 127;
			if (exit_status  != 0 && (!isatty(STDIN_FILENO) && !(tobi1.colon == 1)))
			{
				tobi1.exitcode = exit_status;
				exit(exit_status);
			}
		}

		if (exit_status == 1)
			tobi1.exitcode = 127;
		else
			tobi1.exitcode = exit_status;
	}
}
