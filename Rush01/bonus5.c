/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:41:05 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 13:18:24 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbonus.h"

int	*ft_get_nbr(char *str)
{
	int	i;
	int	j;
	int	*nbr;

	j = 0;
	i = 0;
	nbr = malloc(sizeof(int) * 20);
	if (!nbr)
		return (0);
	while (str[i] != '\0')
	{
		nbr[i] = str[j] - 48;
		i++;
		j = j + 2;
	}
	return (nbr);//tableau de entieres
}

int	ft_check_input(char *str)
{
	int	i;
	int	count_space;
	int	count_int;

	count_space = 0;
	count_int = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count_space++;
		else if (i % 2 == 0 && str[i] >= '1' && str[i] <= '5')
		count_int++;
		else if (i % 2 != 0 && str[i] >= '1' && str[i] <= '5')
			return (0);
		i++;
	}
	if (count_space != 19 || count_int != 20)
		return (0);
	return (1);
}

int	ft_solve(int tab[5][5], int nbr[20], int pos)
{
	int	nb;

	nb = 1;
	if (pos == 25)
		return (1);
	while (nb <= 5)
	{
		tab[pos / 5][pos % 5] = nb;
		if (ft_check_double(tab, nb, pos) && ft_check_rules(tab, nbr, pos))
		{
			if (ft_solve(tab, nbr, pos + 1))
				return (1);
		}
		nb++;
	}
	return (0);
}

int	ft_check_colup(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 5 != 4)
		return (1);
	i = 0;
	while (i <= 4)
	{
		if (tab[i][pos % 5] > max)
		{
			nbtower++;
			max = tab[i][pos % 5];
		}
		i++;
	}
	if (nbtower != nbr[pos % 5])
		return (0);
	return (1);
}


int	ft_check_coldown(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / 5 != 4)
		return (1);
	i = 4;
	while (i >= 0)
	{
		if (tab[i][pos % 5] > max)
		{
			nbtower++;
			max = tab[i][pos % 5];
		}
		i--;
	}
	if (nbtower != nbr[(pos % 5) + 5])
		return (0);
	return (1);
}


int	ft_check_rowleft(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 5 != 4)
		return (1);
	i = 0;
	while (i <= 4)
	{
		if (tab[pos / 5][i] > max)
		{
			nbtower++;
			max = tab[pos / 5][i];
		}
		i++;
	}
	if (nbtower != nbr[(pos / 5) + 10])
		return (0);
	return (1);
}


int	ft_check_rowright(int tab[5][5], int nbr[20], int pos)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % 5 != 4)
		return (1);
	i = 4;
	while (i >= 0)
	{
		if (tab[pos / 5][i] > max)
		{
			nbtower++;
			max = tab[pos / 5][i];
		}
		i--;
	}
	if (nbtower != nbr[(pos / 5) + 15])
		return (0);
	return (1);
}

int	ft_check_double(int tab[5][5], int nb, int pos)
{
	int	i;

	i = 0;
	while (i < pos / 5)
	{
		if (tab[i][pos % 5] == nb)
			return (0);
		i++;
	}
	i = 0;
	while (i < pos % 5)
	{
		if (tab[pos / 5][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_rules(int res[5][5], int nbr[20], int pos)
{
	if (!(ft_check_colup(res, nbr, pos)))
		return (0);
	if (!(ft_check_coldown(res, nbr, pos)))
		return (0);
	if (!(ft_check_rowleft(res, nbr, pos)))
		return (0);
	if (!(ft_check_rowright(res, nbr, pos)))
		return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int res[5][5])
{
	int	i;
	int	j;

	i = 0;
	while(i < 5)
	{
		j = 0;
		while (j < 5)
		{
			ft_putchar(res[i][j] + 48);
			if (j != 4)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char **argv)
{

	int	res[5][5];//tablea qui verra printe
	int	*nbr;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	nbr = ft_get_nbr(argv[1]);//save the chain of char in the array  of int *nbr
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
