/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:55:17 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 18:40:49 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int	*ft_get_nbr(char *str)
{
	int	i;
	int	j;
	int	*nbr;

	j = 0;
	i = 0;
	nbr = malloc(sizeof(int) * 28);
	if (!nbr)
		return (0);
	while (str[i] != '\0')
	{
		nbr[i] = str[j] - 48;
		i++;
		j = j + 2;
	}
	return (nbr);
}

void	ft_print_tab(int res[7][7])
{
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			ft_putchar(res[i][j] + 48);
			if (j != 5)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
