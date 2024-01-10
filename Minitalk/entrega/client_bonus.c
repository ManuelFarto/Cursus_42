/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:14:48 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/09 16:38:11 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#include "minitalk.h"

static void	sig_handler(int sig)
{
	static int	r = 0;

	if (sig == SIGUSR1)
		++r;
	else
	{
		exit(0);
	}
}

void	ft_send_singal(int pid, char *str)
{
	int				bit;
	unsigned char	c;

	while (*str)
	{
		bit = 8;
		c = *str++;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error Invalid Arguments\n", STDERR_FILENO);
		return (1);
	}
	signal (SIGUSR1, sig_handler);
	signal (SIGUSR2, sig_handler);
	ft_send_singal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
