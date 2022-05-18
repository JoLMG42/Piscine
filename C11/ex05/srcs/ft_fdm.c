/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:41:02 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 09:41:27 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int			tab[10];
	long int	nbr;
	int			i;

	nbr = nb;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
	}
	i = 0;
	while (nbr > 0)
	{
		tab[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	i -= 1;
	while (i >= 0)
	{
		write(1, &tab[i], 1);
		i--;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	posi;

	i = 0;
	nb = 0;
	posi = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			posi = posi * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * posi);
}
