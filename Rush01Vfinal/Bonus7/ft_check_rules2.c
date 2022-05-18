/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rules2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:17:53 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 21:11:28 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	ft_check_input(char *str)
{
	int	i;
	int	count_space;
	int	count_int;

	count_space = 0;
	count_int = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count_space++;
		else if (i % 2 == 0 && str[i] >= '1' && str[i] <= '7')
		count_int++;
		else if (i % 2 != 0 && str[i] >= '1' && str[i] <= '7')
			return (0);
		i++;
	}
	if (count_space != 27 || count_int != 28 || i != 55)
		return (0);
	return (1);
}

int	ft_check_double(int tab[7][7], int nb, int pos)
{
	int	i;

	i = 0;
	while (i < pos / 7)
	{
		if (tab[i][pos % 7] == nb)
			return (0);
		i++;
	}
	i = 0;
	while (i < pos % 7)
	{
		if (tab[pos / 7][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_rules(int res[7][7], int nbr[28], int pos)
{
	if (!(ft_check_colup(res, nbr, pos)))
		return (0);
	if (!(ft_check_coldown(res, nbr, pos)))
		return (0);
	if (!(ft_check_rowleft(res, nbr, pos)))
		return (0);
	if (!(ft_check_rowright(res, nbr, pos)))
		return (0);
	return (1);
}
