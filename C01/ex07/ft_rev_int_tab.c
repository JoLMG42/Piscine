/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:47:15 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/18 19:20:48 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}
