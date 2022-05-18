/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:31:58 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 16:22:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRUSH_H
#define	LIBRUSH_H

#include <stdlib.h>
#include <unistd.h>

int     ft_check_rules(int tab[4][4], int *nbr, int pos);
int     *ft_get_nbr(char *str);
int     ft_check_input(char *str);
int     ft_solve(int tab[4][4], int nbr[16], int pos);
int     ft_check_colup(int tab[4][4], int nbr[16], int pos);
int     ft_check_coldown(int tab[4][4], int nbr[16], int pos);	
int     ft_check_rowleft(int tab[4][4], int nbr[16], int pos);
int     ft_check_rowright(int tab[4][4], int nbr[16], int pos);
int     ft_check_double(int tab[4][4], int nb, int pos);
void    ft_putchar(char c);
void    ft_print_tab(int res[4][4]);

#endif



