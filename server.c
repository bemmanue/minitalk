
#include "minitalk.h"

t_info info;

void	handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;

	if (signum == SIGUSR1)
		info.character += (0 << info.index);
	else if (signum == SIGUSR2)
		info.character += (1 << info.index);
	info.index++;
	if (info.index == 8)
	{
		write(1, &(info.character), 1);
		info.index = 0;
		info.character = 0b00000000;
	}
	if (kill(siginfo->si_pid, SIGUSR1))
		terminate();
}

int main(void)
{
	struct sigaction act;

	info.character = 0b00000000;
	info.index = 0;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL))
		terminate();
	if (sigaction(SIGUSR2, &act, NULL))
		terminate();
	printf("Server PID: %d\n", getpid());
	while (1)
		sleep (1);
	return (0);
}
