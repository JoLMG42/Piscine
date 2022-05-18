/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:31:58 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 18:42:15 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRUSH_H
#define	LIBRUSH_H

#include <stdlib.h>
#include <unistd.h>

int     ft_check_double(int tab[7][7], int nb, int pos);
int     ft_check_rules(int tab[7][7], int *nbr, int pos);
int     *ft_get_nbr(char *str);
int     ft_check_input(char *str);
int     ft_solve(int tab[7][7], int nbr[28], int pos);
int     ft_check_colup(int tab[7][7], int nbr[28], int pos);
int     ft_check_coldown(int tab[7][7], int nbr[28], int pos);	
int     ft_check_rowleft(int tab[7][7], int nbr[28], int pos);
int     ft_check_rowright(int tab[7][7], int nbr[28], int pos);
int     ft_check_double(int tab[7][7], int nb, int pos);
void    ft_putchar(char c);
void    ft_print_tab(int res[7][7]);

#endif



