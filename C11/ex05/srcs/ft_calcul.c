/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:40:23 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 09:40:49 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_do_op.h"

void	addition(int a, int b)
{
	int	c;

	c = a + b;
	ft_putnbr(c);
}

void	multiplication(int a, int b)
{
	int	c;

	c = a * b;
	ft_putnbr(c);
}

void	soustraction(int a, int b)
{
	int	c;

	c = a - b;
	ft_putnbr(c);
}

void	division(int a, int b)
{
	int	c;

	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	else
	{
		c = a / b;
		ft_putnbr(c);
	}
}

void	modulo(int a, int b)
{
	int	c;

	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	else
	{
		c = a % b;
		ft_putnbr(c);
	}
}
