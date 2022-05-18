/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:31:22 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 19:58:54 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	ft_check_colup(int tab[8][8], int nbr[32], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 8 != 7)
		return (1);
	i = 0;
	while (i <= 7)
	{
		if (tab[i][pos % 8] > max)
		{
			nbtower++;
			max = tab[i][pos % 8];
		}
		i++;
	}
	if (nbtower != nbr[pos % 8])
		return (0);
	return (1);
}

int	ft_check_coldown(int tab[8][8], int nbr[32], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 8 != 7)
		return (1);
	i = 7;
	while (i >= 0)
	{
		if (tab[i][pos % 8] > max)
		{
			nbtower++;
			max = tab[i][pos % 8];
		}
		i--;
	}
	if (nbtower != nbr[(pos % 8) + 8])
		return (0);
	return (1);
}

int	ft_check_rowleft(int tab[8][8], int nbr[32], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 8 != 7)
		return (1);
	i = 0;
	while (i <= 7)
	{
		if (tab[pos / 8][i] > max)
		{
			nbtower++;
			max = tab[pos / 8][i];
		}
		i++;
	}
	if (nbtower != nbr[(pos / 8) + 16])
		return (0);
	return (1);
}

int	ft_check_rowright(int tab[8][8], int nbr[32], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 8 != 7)
		return (1);
	i = 7;
	while (i >= 0)
	{
		if (tab[pos / 8][i] > max)
		{
			nbtower++;
			max = tab[pos / 8][i];
		}
		i--;
	}
	if (nbtower != nbr[(pos / 8) + 24])
		return (0);
	return (1);
}
