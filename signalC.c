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

