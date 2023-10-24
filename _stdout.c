#include "hsh.h"
/**
 * _stdout - ======
 * @str: =====
 */
void _stdout(char *str)
{
	write(1, str, strlen(str));

}
