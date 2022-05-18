/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:03:20 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/31 23:30:59 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!s)
		return (0);
	i = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
