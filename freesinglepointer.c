#include "hsh.h"
/**
 * freesinglepointer - ============
 * @args: =============
 */
void freesinglepointer(char **args)
{
	int j = 0;

	while (args[j])
	{
		free(args[j]);
		j++;
	}
}
