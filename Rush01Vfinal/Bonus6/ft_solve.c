/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:52:58 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 19:50:32 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	ft_solve(int tab[6][6], int nbr[24], int pos)
{
	int	nb;

	nb = 1;
	if (pos == 36)
		return (1);
	while (nb <= 6)
	{
		tab[pos / 6][pos % 6] = nb;
		if (ft_check_double(tab, nb, pos) && ft_check_rules(tab, nbr, pos))
		{
			if (ft_solve(tab, nbr, pos + 1))
				return (1);
		}
		nb++;
	}
	return (0);
}
