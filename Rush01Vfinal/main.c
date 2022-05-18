/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:41:05 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 11:34:09 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	res[4][4];
	int	*nbr;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	nbr = ft_get_nbr(argv[1]);
	if (!ft_check_input(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_solve(res, nbr, 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		ft_print_tab(res);
	return (0);
}	
