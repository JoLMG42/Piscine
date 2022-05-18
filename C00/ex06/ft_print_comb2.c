/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:57:08 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/18 15:56:49 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printnb(int nb)
{
	ft_putchar(nb / 10 + '0');
	ft_putchar(nb % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < 98)
	{
		if (a < b)
		{
			ft_printnb(a);
			write(1, " ", 1);
			ft_printnb(b);
			write(1, ", ", 2);
		}
		b++;
		if (b > 99)
		{
			a++;
			b = 0;
		}
	}
	ft_printnb(98);
	write(1, " ", 1);
	ft_printnb(99);
}
