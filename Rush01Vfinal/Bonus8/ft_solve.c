/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:52:58 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 19:56:35 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	ft_solve(int tab[8][8], int nbr[32], int pos)
{
	int	nb;

	nb = 1;
	if (pos == 64)
		return (1);
	while (nb <= 8)
	{
		tab[pos / 8][pos % 8] = nb;
		if (ft_check_double(tab, nb, pos) && ft_check_rules(tab, nbr, pos))
		{
			if (ft_solve(tab, nbr, pos + 1))
				return (1);
		}
		nb++;
	}
	return (0);
}
