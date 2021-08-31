
#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include "libft/libft.h"

void	handle_zero(int signum, siginfo_t *info, void *context);
void	handle_one(int signum, siginfo_t *info, void *context);

void	send_message(char *message, int pid);
void	send_char(char c, int pid);

#endif