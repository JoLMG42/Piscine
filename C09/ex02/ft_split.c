/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:52:57 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/02 10:09:05 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	ft_check_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_lenword(char *charset, char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_check_charset(charset, str[i]) == 0)
		i++;
	return (i);
}

int	ft_countwords(char *charset, char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_check_charset(charset, str[i]) == 1)
			i++;
		else
		{
			while (str[i] && ft_check_charset(charset, str[i]) == 0)
				i++;
			count++;
		}
	}
	return (count);
}

char	*ft_cpy(char *charset, char *str, int n)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_lenword(charset, str) + 1));
	if (!cpy)
		return (0);
	while (str[i] && i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**s;

	s = malloc(sizeof(char *) * (ft_countwords(charset, str) + 1));
	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_check_charset(charset, str[i]) == 1)
			i++;
		else
		{
			s[j] = ft_cpy(charset, str + i, ft_lenword(charset, str + i));
			j++;
			i = i + ft_lenword(charset, str + i);
		}
	}
	return (s);
}
