/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:45:50 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/26 18:41:20 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tab(char *queens)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_check(char *queens, int col)
{
	int	i;

	i = col - 1;
	while (i >= 0)
	{
		if (queens[col] == queens[i])
			return (0);
		if (queens[col] == queens[i] - (col - i))
			return (0);
		if (queens[col] == queens[i] + (col - i))
			return (0);
		i--;
	}
	return (1);
}

void	ft_back(char *queens, int *counter, int col)
{
	if (col == 10)
	{
		ft_print_tab(queens);
		*counter = *counter + 1;
		return ;
	}
	queens[col] = 0;
	while (queens[col] < 10)
	{
		if (ft_check(queens, col))
			ft_back(queens, counter, col + 1);
		queens[col]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	queens[10];
	int		counter;

	counter = 0;
	ft_back(queens, &counter, 0);
	return (counter);
}
