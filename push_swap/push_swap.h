/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:57:54 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/18 17:18:37 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*  *Libresias*  */

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/*  *Funciones*  */

long	ft_atol(const char *str);
int		ft_numerror(char *nums);
void	*ft_push_swap(int size, char **argv);
char	**ft_split(char const *s, char c, int *size);
size_t	ft_strlen(const char *s);
void	ft_free(char **trash);
int		ft_norep(char **nums);
int		ft_numover(long *nums, int size);
int		ft_isorder(int size, int *index);
void	ft_bzero(int *s, int n, int o);
int		*ft_index(int size, long *nums);
void	ft_alg(int size, int *index);
void	ft_sa(int *index);
void	ft_ra(int size, int *index);
void	ft_rra(int size, int *index);
void	ft_pb(int size, int *index, int *stackb);
void	ft_sb(int *stackb);
void	ft_rb(int size, int *stackb);
void	ft_rrb(int size, int *stackb);
void	ft_pa(int size, int *stackb, int *index);
int		ft_minnum(int size, int *index);
int		ft_maxnum(int chsize, int *index);
int		ft_numsize(int *index);
void	ft_cheatingtool(int size, int *index, int min);
void	ft_cheatingtool2(int size, int *index, int min);
void	ft_takeout(int chsize, int numpos, int *index, int *stackb);
int		ft_outmoves(int chsize, int numpos);
int		ft_minmoves(int size, int chsize, int *index);

#endif