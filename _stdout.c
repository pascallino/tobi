#include "hsh.h"
/**
 * _stdout - ======
 * @str: =====
 * @n: ======================
 */
void _stdout(char *str, int n)
{
	write(n, str, strlen(str));

}
