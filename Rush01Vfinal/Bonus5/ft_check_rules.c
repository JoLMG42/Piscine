/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:31:22 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 17:47:02 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	ft_check_colup(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 5 != 4)
		return (1);
	i = 0;
	while (i <= 4)
	{
		if (tab[i][pos % 5] > max)
		{
			nbtower++;
			max = tab[i][pos % 5];
		}
		i++;
	}
	if (nbtower != nbr[pos % 5])
		return (0);
	return (1);
}

int	ft_check_coldown(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 5 != 4)
		return (1);
	i = 4;
	while (i >= 0)
	{
		if (tab[i][pos % 5] > max)
		{
			nbtower++;
			max = tab[i][pos % 5];
		}
		i--;
	}
	if (nbtower != nbr[(pos % 5) + 5])
		return (0);
	return (1);
}

int	ft_check_rowleft(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 5 != 4)
		return (1);
	i = 0;
	while (i <= 4)
	{
		if (tab[pos / 5][i] > max)
		{
			nbtower++;
			max = tab[pos / 5][i];
		}
		i++;
	}
	if (nbtower != nbr[(pos / 5) + 10])
		return (0);
	return (1);
}

int	ft_check_rowright(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 5 != 4)
		return (1);
	i = 4;
	while (i >= 0)
	{
		if (tab[pos / 5][i] > max)
		{
			nbtower++;
			max = tab[pos / 5][i];
		}
		i--;
	}
	if (nbtower != nbr[(pos / 5) + 15])
		return (0);
	return (1);
}
