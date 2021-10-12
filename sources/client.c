/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:29:35 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 16:29:37 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 8;
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
		usleep (50);
	}
}

void	send_message(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
	send_char('\n', pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = get_pid(argv[1]);
		if (pid)
		{
			message = argv[2];
			send_message(message, pid);
			ft_putstr_fd("The message has been received\n", 1);
		}
		else
			ft_putstr_fd("Invalid PID\n", 2);
	}
	else
		ft_putstr_fd("Usage: ./client [Server PID] [Message]\n", 1);
	return (0);
}
