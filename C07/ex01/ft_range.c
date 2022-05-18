/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:28:22 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/31 23:34:44 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*s;
	int	i;
	int	som;

	som = max - min;
	if (min >= max)
		return (0);
	s = malloc(sizeof(int) * som);
	if (!s)
		return (0);
	i = 0;
	while (i < som)
	{
		s[i] = min;
		i++;
		min++;
	}
	return (s);
}
