#include <unistd.h>

void	printStr(char *str)
{
	int	c;

	c = 0;
	while (str[c] != 0)
	{
		write(1, &str[c], 1);
		c++;
	}
}
