/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:11:23 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/07 19:11:25 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_info
{
	char		character;
	int			index;
}				t_info;

void	handler(int signum, siginfo_t *siginfo, void *context);
int		get_pid(char *pid);
void	send_message(char *message, int pid);
void	send_char(char c, int pid);
void	check_reception(int signum);
void	terminate(void);

#endif
