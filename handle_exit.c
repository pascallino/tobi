#include "hsh.h"
/**
 * handle_exit - exit handler
 * @args: =========
 * @command: =======
 */
void handle_exit(char *args, char *command)
{
	if (args != NULL)/*./hsh: 1: exit: Illegal number: HBTN*/
	{
		int no;
		if (checkforletter(args) == 2)
		{
			_stdout("./hsh: 1: exit: Illegal number: ", 2);
			_stdout(args, 2);
			_stdout("\n", 2);
			free(command);
			tobi1.exitcode = 2;
			exit(2);
		}
		else
		{
			no = atoi(args);
			free(command);
			tobi1.exitcode = no;
			exit(no);
		}
	}
}
