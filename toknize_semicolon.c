#include  "hsh.h"

void finalexecution(char **args)
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
		execute(ptr);
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
		finalexecution(arg);
	}
	i = 0;


}
