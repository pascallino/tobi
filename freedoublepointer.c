#include "hsh.h"
/**
 * freedoublepointer - ============
 * @args: =============
 */
void freedoublepointer(char **args)
{
	int j = 0;

	while (args[j])
	{
		free(args[j]);
		j++;
	}
	free(args);
}
