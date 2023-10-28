#include  "hsh.h"

void finalexecution(char **args, char *command)
{
	int i = 0;
	int k = 0;
	int j = 0;
	static char *ptr[12000] = {NULL};
	char *token = NULL;

	while (args[i])
	{
		token = strtok(args[i], " \n\t\r");
		while (token)
		{
			if (token[0] == '#')
			{
				ptr[k] = NULL;
				break;
			}
			ptr[k] = token;
			token = strtok(NULL, " \n\t\r");
			k++;
		}
		ptr[k] = NULL;
		k = 0;
		if (strcmp(ptr[0], "exit") == 0)
		{
			if (ptr[1] == NULL)
			{
				free(command);
				exit(0);
			}
			else
			{
				handle_exit(ptr[1], command);
			}
		}
			execute(ptr, ptr[1]);
			i++;
		}
		i = 0;


	}



	/**
	 * tokenizeOR - tokenize OR || operator
	 * @command: command
	 * Return: return command
	 *     */
	void tokenize_semicolon(char *command)
	{
		char *token = NULL;
		static char *arg[12000] = {NULL};
		int i = 0;

		token = strtok(command, ";\n");
		while (token)
		{
			if (token[0] == '#')
			{
				arg[i] = NULL;
				break;
			}
			arg[i] = token;
			token = strtok(NULL, ";\n");
			i++;
		}
		arg[i] = NULL;
		if (arg[0] != NULL)
		{
			finalexecution(arg, command);
		}
		i = 0;


	}
