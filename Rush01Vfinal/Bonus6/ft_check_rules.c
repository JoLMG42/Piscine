/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:31:22 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 18:10:55 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	ft_check_colup(int tab[6][6], int nbr[24], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 6 != 5)
		return (1);
	i = 0;
	while (i <= 5)
	{
		if (tab[i][pos % 6] > max)
		{
			nbtower++;
			max = tab[i][pos % 6];
		}
		i++;
	}
	if (nbtower != nbr[pos % 6])
		return (0);
	return (1);
}

int	ft_check_coldown(int tab[6][6], int nbr[24], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 6 != 5)
		return (1);
	i = 5;
	while (i >= 0)
	{
		if (tab[i][pos % 6] > max)
		{
			nbtower++;
			max = tab[i][pos % 6];
		}
		i--;
	}
	if (nbtower != nbr[(pos % 6) + 6])
		return (0);
	return (1);
}

int	ft_check_rowleft(int tab[6][6], int nbr[24], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 6 != 5)
		return (1);
	i = 0;
	while (i <= 5)
	{
		if (tab[pos / 6][i] > max)
		{
			nbtower++;
			max = tab[pos / 6][i];
		}
		i++;
	}
	if (nbtower != nbr[(pos / 6) + 12])
		return (0);
	return (1);
}

int	ft_check_rowright(int tab[6][6], int nbr[24], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 6 != 5)
		return (1);
	i = 5;
	while (i >= 0)
	{
		if (tab[pos / 6][i] > max)
		{
			nbtower++;
			max = tab[pos / 6][i];
		}
		i--;
	}
	if (nbtower != nbr[(pos / 6) + 18])
		return (0);
	return (1);
}
