/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:30:44 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 16:30:46 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signum == SIGUSR1)
		g_info.character += (0 << g_info.index);
	else if (signum == SIGUSR2)
		g_info.character += (1 << g_info.index);
	g_info.index++;
	if (g_info.index == 8)
	{
		write(1, &(g_info.character), 1);
		g_info.index = 0;
		g_info.character = 0b00000000;
	}
}

int	main(void)
{
	struct sigaction	act;

	g_info.character = 0b00000000;
	g_info.index = 0;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL))
		terminate();
	if (sigaction(SIGUSR2, &act, NULL))
		terminate();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		sleep (1);
	return (0);
}
