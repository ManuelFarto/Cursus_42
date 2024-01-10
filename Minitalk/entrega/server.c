/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:49:51 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/09 13:35:25 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#include "minitalk.h"

void	ft_rsignal(int sig, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	static pid_t			pd = 0;

	(void)context;
	if (!pd)
		pd = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++bit == 8)
	{
		bit = 0;
		if (!c)
		{
			kill(pd, SIGUSR2);
			pd = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pd, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	act.sa_sigaction = ft_rsignal;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
