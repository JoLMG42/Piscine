/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:26:13 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/28 16:48:36 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	**ft_swap(int ac, char **av)
{
	int		i;
	int		j;
	char	*swap;

	i = 1;
	while (i != ac)
	{
		j = 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) < 0)
			{
				swap = av[i];
				av[i] = av[j];
				av[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (av);
}

int	main(int ac, char **av)
{
	int	i;

	ft_swap(ac, av);
	i = 1;
	while (av[i])
	{
		ft_putstr(av[i]);
		i++;
	}
	return (0);
}
