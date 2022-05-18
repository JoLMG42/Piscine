/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:14:20 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 20:33:45 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strslen(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		if (i != size - 1)
			len = len + ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *sep)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (sep[j])
	{
		dest[i] = sep[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;

	if (size == 0)
	{
		s = malloc(1);
		s[0] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * ft_strslen(size, strs, sep) + 1);
	if (!s)
		return (0);
	i = -1;
	while (++i < ft_strslen(size, strs, sep))
		s[i] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(s, strs[i]);
		if (i < size - 1)
			s = ft_strcat(s, sep);
		i++;
	}
	return (s);
}

int main(int ac, char **av)
{
	printf("%s\n",ft_strjoin(ac, av, "|SEP|"));
}
