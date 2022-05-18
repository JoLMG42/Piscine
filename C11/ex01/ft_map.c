/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:57:41 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 14:07:14 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*s;
	int	i;

	i = 0;
	s = malloc(sizeof(int) * (length));
	while (i < length)
	{
		s[i] = (*f)(tab[i]);
		i++;
	}
	return (s);
}
