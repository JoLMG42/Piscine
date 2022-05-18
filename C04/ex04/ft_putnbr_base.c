/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:22:40 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/25 10:42:55 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_convbase(long nbr, char *base, int size)
{
	if (nbr >= size)
		ft_convbase(nbr / size, base, size);
	write(1, &base[nbr % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long		n;
	int			size;

	n = nbr;
	size = ft_check_base(base);
	if (size)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		ft_convbase(n, base, size);
	}
}
