#include "hsh.h"
/**
 * _stdout - ======
 * @str: =====
 */
void _stdout(char *str, int n)
{
	write(n, str, strlen(str));

}
