/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:33:36 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/09 07:47:53 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H


#include "libft/libft.h"
#include <signal.h>



#define TRUE SIGUSR1 
#define FALSE SIGUSR2 

void    ft_send_singal(int pid, char *s);

void    ft_rsignal(int sig, siginfo_t *info, void *ucontent);

#endif