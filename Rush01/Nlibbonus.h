/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nlibbonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:31:58 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 17:00:07 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRUSH_H
#define	LIBRUSH_H

#include <stdlib.h>
#include <unistd.h>

int     ft_check_rules(int **tab, int *nbr, int pos, int N);
int     *ft_get_nbr(char *str, int N);
int     ft_check_input(char *str);
int     ft_solve(int **tab, int *nbr, int pos, int N);
int     ft_check_colup(int **tab, int *nbr, int pos, int N);
int     ft_check_coldown(int **tab, int *nbr, int pos, int N);	
int     ft_check_rowleft(int **tab, int *nbr, int pos, int N);
int     ft_check_rowright(int **tab, int *nbr, int pos, int N);
int     ft_check_double(int **tab, int nb, int pos, int N);
void    ft_putchar(char c);
void    ft_print_tab(int **res, int N);
int	**ft_malloc_tab(int N);

#endif



