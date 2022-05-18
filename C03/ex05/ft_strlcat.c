/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:29:55 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/26 11:40:24 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	len2;
	unsigned int	l;

	len = ft_strlen(dest);
	len2 = ft_strlen(src);
	l = size - len - 1;
	if (src && dest)
	{
		if (len >= size || !size)
			return (len2 + size);
		i = 0;
		while (src[i] != '\0' && i < l)
		{
			dest[len + i] = src[i];
			i++;
		}
		dest[len + i] = '\0';
		return (len + len2);
	}
	else
		return (0);
}
