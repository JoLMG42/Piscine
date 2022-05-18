/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:45:19 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 13:58:37 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	check_diff(int a, int b)
{
	if ((a < 0 && b < 0) || (a > 0 && b > 0))
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	diff;

	i = 0;
	if (length == 0 || length == 1)
		return (1);
	diff = (*f)(tab[0], tab[1]);
	while (i < length - 1)
	{
		if (diff == 0)
			diff = (*f)(tab[i], tab[i + 1]);
		if ((*f)(tab[i], tab[i + 1]) != 0
			&& check_diff(diff, (*f)(tab[i], tab[i + 1])) == 0)
			return (0);
		i++;
	}
	return (1);
}
