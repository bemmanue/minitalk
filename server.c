
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "libft/libft.h"

void	handle_zero(int signum)
{
	if (signum == SIGUSR1)
		write(1, "0\n", 2);
}

void	handle_one(int signum)
{
	if (signum == SIGUSR2)
		write(1, "1\n", 2);
}

int main(void)
{
	pid_t pid;
	struct sigaction act_zero;
	struct sigaction act_one;

	pid = getpid();
	printf("pid:	%d\n", pid);
	act_zero.sa_flags = SA_SIGINFO;
	act_one.sa_flags = SA_SIGINFO;
	act_zero.sa_handler = handle_zero;
	act_one.sa_handler = handle_one;

	sigaction(SIGUSR1, &act_zero, NULL);
	sigaction(SIGUSR2, &act_one, NULL);
	while (1)
		;
	return (0);
}
