/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rules2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:17:53 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 22:23:39 by jtaravel         ###   ########.fr       */
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
		else if (i % 2 == 0 && str[i] >= '1' && str[i] <= '4')
			count_int++;
		else if (i % 2 != 0 && str[i] >= '1' && str[i] <= '4')
			return (0);
		i++;
	}
	if (count_space != 15 || count_int != 16 || i != 31)
		return (0);
	return (1);
}

int	ft_check_double(int tab[4][4], int nb, int pos)
{
	int	i;

	i = 0;
	while (i < pos / 4)
	{
		if (tab[i][pos % 4] == nb)
			return (0);
		i++;
	}
	i = 0;
	while (i < pos % 4)
	{
		if (tab[pos / 4][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_rules(int res[4][4], int nbr[16], int pos)
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
