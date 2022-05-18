/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nbonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:41:05 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/24 19:13:03 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Nlibbonus.h"

int	*ft_get_nbr(char *str, int N)
{
	int	i;
	int	j;
	int	*nbr;

	j = 0;
	i = 0;
	nbr = malloc(sizeof(int) * (N * N));
	if (!nbr)
		return (0);
	while (str[i] != '\0')
	{
		nbr[i] = str[j] - 48;
		i++;
		j = j + 2;
	}
	return (nbr);
}

int	ft_check_input(char *str)
{
	int	i;
	int	count_space;
	int	count_int;
	int	max;

	count_space = 0;
	count_int = 0;
	max = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count_space++;
		else if (i % 2 == 0 && str[i] >= '1' && str[i] <= '9')
		{
			count_int++;
			if ((str[i] - '0') > max)
				max = str[i] - '0';
		}
		else if (i % 2 != 0 && str[i] >= '1' && str[i] <= '9')
			return (0);
		i++;
	}
	if (count_space != ((max * max) - 1) || count_int != (max * max))
		return (0);
	return (max);
}

int	**ft_malloc_tab(int N)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(*tab) * N);
	while (i < N)
	{
		tab[i] = malloc(sizeof(**tab) * N);
		i++;
	}
	return (tab);
}

/*
int	**ft_malloc_tab(int N)
{
	int	**tab;
	int	i;

	tab = malloc(N * sizeof(int *));
	if (!tab)
		return (0);
	i = -1;
	while (++i < N)
	{
		tab[i] = malloc(N * sizeof(int));
		if (!tab[i])
			return (0);
	}
	return (tab);
}
*/
int	ft_solve(int **tab, int *nbr, int pos, int N)
{
	int	nb;

	nb = 1;
	if (pos == (N * N))
		return (1);
	while (nb <= N)
	{
		tab[pos / N][pos % N] = nb;
		if (ft_check_double(tab, nb, pos, N) && ft_check_rules(tab, nbr, pos, N))
		{
			if (ft_solve(tab, nbr, pos + 1, N))
				return (1);
		}
		nb++;
	}
	return (0);
}

int	ft_check_colup(int **tab, int *nbr, int pos, int N)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / N != (N - 1))
		return (1);
	i = 0;
	while (i <= (N - 1))
	{
		if (tab[i][pos % N] > max)
		{
			nbtower++;
			max = tab[i][pos % N];
		}
		i++;
	}
	if (nbtower != nbr[pos % N])
		return (0);
	return (1);
}


int	ft_check_coldown(int **tab, int *nbr, int pos, int N)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos / N != (N - 1))
		return (1);
	i = N - 1;
	while (i >= 0)
	{
		if (tab[i][pos % N] > max)
		{
			nbtower++;
			max = tab[i][pos % N];
		}
		i--;
	}
	if (nbtower != nbr[(pos % N) + N])
		return (0);
	return (1);
}


int	ft_check_rowleft(int **tab, int *nbr, int pos, int N)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % N != (N - 1))
		return (1);
	i = 0;
	while (i <= (N - 1))
	{
		if (tab[pos / N][i] > max)
		{
			nbtower++;
			max = tab[pos / N][i];
		}
		i++;
	}
	if (nbtower != nbr[(pos / N) + (N * 2)])
		return (0);
	return (1);
}


int	ft_check_rowright(int **tab, int *nbr, int pos, int N)
{
	int	i;
	int	max;
	int	nbtower;

	nbtower = 0;
	max = 0;
	if (pos % N != (N - 1))
		return (1);
	i = N - 1;
	while (i >= 0)
	{
		if (tab[pos / N][i] > max)
		{
			nbtower++;
			max = tab[pos / N][i];
		}
		i--;
	}
	if (nbtower != nbr[(pos / N) + (N * 3)])
		return (0);
	return (1);
}

int	ft_check_double(int **tab, int nb, int pos, int N)
{
	int	i;

	i = 0;
	while (i < pos / N)
	{
		if (tab[i][pos % N] == nb)
			return (0);
		i++;
	}
	i = 0;
	while (i < pos % N)
	{
		if (tab[pos / N][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_rules(int **res, int *nbr, int pos, int N)
{
	if (!(ft_check_colup(res, nbr, pos, N)))
		return (0);
	if (!(ft_check_coldown(res, nbr, pos, N)))
		return (0);
	if (!(ft_check_rowleft(res, nbr, pos, N)))
		return (0);
	if (!(ft_check_rowright(res, nbr, pos, N)))
		return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int **res, int N)
{
	int	i;
	int	j;


	i = 0;
	while(i < N)
	{
		j = 0;
		while (j < N)
		{
			ft_putchar(res[i][j] + 48);
			if (j != (N - 1))
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char **argv)
{

	int	**res;
	int	*nbr;
	int	N;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	N = ft_check_input(argv[1]);
	if (N == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	nbr = ft_get_nbr(argv[1], N);
	res = ft_malloc_tab(N);
	if (!ft_solve(res, nbr, 0, N))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		ft_print_tab(res, N);
	return (0);
	
}	
