
#include "minitalk.h"

void	check_reception(int signum)
{
	(void)signum;
}

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
	struct sigaction	act;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		act.sa_handler = check_reception;
		if (sigaction(SIGUSR1, &act, NULL))
			terminate();
		send_message(message, pid);
		printf("The message has been received\n");
	}
	else
		printf("Write server PID and message you want to send\n");
	return (0);
}
