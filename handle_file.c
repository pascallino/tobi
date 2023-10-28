#include "hsh.h"



void reset_arg(char **arg)
{
int i = 0;

while (arg[i])
{
	arg[i] = NULL;
	i++;
}
}
/**
 * handle_file - executes command in file
 * @filename: filename
 * Return: char **
 */
char handle_file(char *filename)
{
	char line[15000] = {'\0'};
	int fd;
	char *copyline = NULL;
	int arg_count = 0;
	/*char **args = NULL;*/
	size_t nread = 0;
	char *token = NULL;
	char buffer[15000];
	int i = 0;
	int lineLength = 0;
	char *args[15000] = {NULL};

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		_stdout("./hsh: 0: Can't open ", 2);
		_stdout(filename, 2);
		_stdout("\n", 2);
		tobi1.exitcode = 127;
		exit(127);
	}
	while ((nread = read(fd, buffer, 15000)) > 0)
	{
		for (i = 0; i < nread; i++)
		{
			if (buffer[i] == '\n')
			{
				line[lineLength] = '\n';
				line[lineLength + 1] = '\0';
				token = strtok(line, " \n");
				while (token != NULL)
				{
					if (token[0] == '#')
					{
						args[arg_count] = NULL;
						break;
					}
					args[arg_count] = token;
					/*strcpy(args[arg_count], token);*/
					token = strtok(NULL, " \n");
						arg_count++;
				}
				/* check if there is an empty space or newline*/
				token = strtok(args[0], " \n");
				if (token != NULL)
				{
					/*args[arg_count] = NULL;*/
					execute(args, args[1]);
				}
				strcpy(line, "\0");
				reset_arg(args);
				arg_count = 0;
				lineLength = 0;

			}
			else
			{
				line[lineLength] = buffer[i];
				lineLength++;
			}
		}
	}
	/*args[arg_count] = NULL;*/
	close(fd);
}
