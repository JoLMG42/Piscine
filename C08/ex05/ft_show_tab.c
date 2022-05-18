/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:58:09 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/02 15:40:17 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_show_tab(struct s_stock_str *par);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
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
		tab[i] = nbr % 10 + 48;
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		 ft_putchar(tab[i]);
		 i--;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
