/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:33:32 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/31 23:36:47 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*s;
	int	i;
	int	som;

	if (min >= max)
		return (0);
	som = max - min;
	s = malloc(sizeof(int) * som);
	if (!s)
		return (-1);
	i = 0;
	while (i < som)
	{
		s[i] = min;
		i++;
		min++;
	}
	*range = s;
	return (i);
}
