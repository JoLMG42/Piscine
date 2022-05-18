/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:55:30 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/02 20:44:20 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

struct	s_list
{
	int	i;
	char	c;
	char	*str;
	struct	s_list	*next;
};

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
		write(1, &str[i], 1);
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

void	aff(struct s_list *begin)
{
	while (begin)
	{
		if ()
		{
			ft_putstr(begin->str);
			write(1, "\n", 1);
		}
		else if (begin-)
		{
			ft_putnbr(begin->i);
			write(1, "\n", 1);
		}
		begin = begin->next;
	}
}

int main(void)
{
	struct	s_list	elem1;
	struct	s_list	elem2;
	struct	s_list	elem3;
	struct	s_list	*begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = 0;

	elem1.str = "pop";
	elem2.i = 9;
	elem3.i = 4;
	aff(begin);
}


