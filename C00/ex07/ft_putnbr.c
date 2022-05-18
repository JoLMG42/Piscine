/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:44:53 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/18 15:35:31 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

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
