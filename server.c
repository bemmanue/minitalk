
#include "minitalk.h"

t_info info;

void	handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;

	if (signum == SIGUSR1)
		info.c += (0 << info.i);
	else if (signum == SIGUSR2)
		info.c += (1 << info.i);
	info.i++;
	if (info.i == 7)
	{
		write(1, &(info.c), 1);
		info.i = 0;
		info.c = 0b00000000;
	}
}

int main(void)
{
	struct sigaction act;

	info.c = 0b00000000;
	info.i = 0;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL))
		terminate();
	if (sigaction(SIGUSR2, &act, NULL))
		terminate();
	printf("Server PID:		%d\n", getpid());
	while (1)
		sleep (1);
	return (0);
}
