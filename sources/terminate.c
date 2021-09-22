
#include "../includes/minitalk.h"

void	terminate(void)
{
	write(2, "Error\n", 6);
	exit (1);
}