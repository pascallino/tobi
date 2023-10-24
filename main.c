#include "hsh.h"
/**
 * sigint_handler - CTRL C free spaces
 * @signo: =======
 */
void sigint_handler(int signo)
{
	/*Handle SIGINT (Ctrl+C) by freeing allocated memory*/
	(void) signo;
	free(tobi1.cmd);
	exit(0);  /*Terminate the program gracefull*/
}

/**
 * main - entery point
 * @argc: ========
 * argv: =========== 
 */
int main(int argc, char **argv)
{
	static char *arg[15000] = {NULL};
	size_t byte = 0;
	int isecho = 1;
	char *token = NULL;
	int i = 0;

	isecho = isatty(STDIN_FILENO);
	signal(SIGINT, sigint_handler);
	while(1)
	{
		byte = getline(&tobi1.cmd, &byte, stdin);
		if (byte == -1)
		{
			break;
		}
		if (strchr(tobi1.cmd, ';') != NULL)
		{
			tobi1.colon = 1;
			tokenize_semicolon(tobi1.cmd);
			if (isecho == 0)
				break;
			continue;
		}
		else
			tobi1.colon = 0;
		if (strchr(tobi1.cmd, ';') != NULL)
		{
		}
		else if (strchr(tobi1.cmd, '&') != NULL)
		{
			return 0;
		}
		else if (strchr(tobi1.cmd, '|') != NULL)
		{
			return 1;
		}
		else
		{
			token = strtok(tobi1.cmd, " \n\t\r");
			while(token)
			{
				if (token[0] == '#')
				{
					arg[i] = NULL;
					break;
				}
				arg[i] = token;
				token = strtok(NULL, " \n\t\r");
				i++;
			}
			arg[i] = NULL;
			i = 0;
			if (arg[0] == NULL)
			{
				if (isecho == 0)
					break;
				continue;
			}
			if (strcmp(arg[0], "exit") == 0)
			{
				break;
			}
			else if (strcmp(arg[0], "env") == 0)
			{
				while(environ[i])
				{
					_stdout(environ[i], 1);
					_stdout("\n", 1);
					i++;
				}
				i = 0;
				if (isecho == 0)
					break;
				continue;
			}
			else 
			{
				execute(arg);
				if (isecho == 0)
					break;
				continue;
			}

		}
	}
	free(tobi1.cmd);
	return (0);

}
