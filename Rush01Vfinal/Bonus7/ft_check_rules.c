/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:31:22 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 18:39:56 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	ft_check_colup(int tab[7][7], int nbr[28], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 7 != 6)
		return (1);
	i = 0;
	while (i <= 6)
	{
		if (tab[i][pos % 7] > max)
		{
			nbtower++;
			max = tab[i][pos % 7];
		}
		i++;
	}
	if (nbtower != nbr[pos % 7])
		return (0);
	return (1);
}

int	ft_check_coldown(int tab[7][7], int nbr[28], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 7 != 6)
		return (1);
	i = 5;
	while (i >= 0)
	{
		if (tab[i][pos % 7] > max)
		{
			nbtower++;
			max = tab[i][pos % 7];
		}
		i--;
	}
	if (nbtower != nbr[(pos % 7) + 7])
		return (0);
	return (1);
}

int	ft_check_rowleft(int tab[7][7], int nbr[28], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 7 != 6)
		return (1);
	i = 0;
	while (i <= 6)
	{
		if (tab[pos / 7][i] > max)
		{
			nbtower++;
			max = tab[pos / 7][i];
		}
		i++;
	}
	if (nbtower != nbr[(pos / 7) + 14])
		return (0);
	return (1);
}

int	ft_check_rowright(int tab[7][7], int nbr[28], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 7 != 6)
		return (1);
	i = 6;
	while (i >= 0)
	{
		if (tab[pos / 7][i] > max)
		{
			nbtower++;
			max = tab[pos / 7][i];
		}
		i--;
	}
	if (nbtower != nbr[(pos / 7) + 21])
		return (0);
	return (1);
}
