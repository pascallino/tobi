#ifndef HSH_H
#define HSH_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <error.h>
#include <fcntl.h>
#include <signal.h>
extern char **environ;
/**
 * struct tobi - ==============
 * @tbi2: =======
 * @tobi_: ==========
 */
typedef struct tobi
{
	char *tbi2;
	void (*tobi_)(char *, const char *);
} tobi;

/**
 * struct data_t - application data
 * @cmd: ======
 * @app_name: =======
 * @errnum: ==========
 * @colon: =====
 */
typedef struct data_t
{
	char *cmd;
	char *app_name;
	int errnum;
	int colon;
} data_t;
data_t tobi1;
/*data_t tobi2;*/

void _stdout(char *str);


#endif