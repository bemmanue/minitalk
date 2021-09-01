
#include "minitalk.h"

void	send_char(char c, int pid)
{
	int i;

	i = 7;
	while (i--)
	{
		if (c & 1)
		{
			if (kill((pid_t) pid, SIGUSR2))
				terminate();
		}
		else
		{
			if (kill((pid_t) pid, SIGUSR1))
				terminate();
		}
		c >>= 1;
		usleep (40);
	}
}

void	send_message(char *message, int pid)
{
	int i;

	i = 0;
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
	send_char('\n', pid);
}

int main(int argc, char **argv)
{
	int					pid;
	char				*message;

	if (argc == 3)
	{
		message = argv[2];
		pid = ft_atoi(argv[1]);
		send_message(message, pid);
	}
	else
		printf("Write server PID and message you want to send\n");
	return (0);
}
