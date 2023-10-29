#include  "hsh.h"
/**
 * checkforletter - ========================
 * @str: ======================
 * Return: ======================
 */
int checkforletter(char *str)
{

	int i  = 0;

	while (str[i])
	{
		if (str[i] < '0' ||  str[i] > '9')
		{
			return (2);
		}
		i++;
	}
	return (0);
}


