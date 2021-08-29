
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include <signal.h>

void send_message(char *message)
{
	int i;

	i = 0;
	while (message[i])
	{


	}
}

int main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;
	int		k;

	i = 0;
	message = argv[2];
	pid = 0;
	if (argc == 3)
	{
		ft_putstr_fd("server's pid:	", 1);
		pid = ft_atoi(argv[1]);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd("\n", 1);
		send_message(massage);
	}
	else
		printf("argument hasn't been got");
	return (0);
}
