/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:19:17 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/26 11:44:53 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi_base(char *str, char *base);

int	ft_check_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-' || str[i] == ' '
			|| (str[i] >= 9 && str[i] <= 13))
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_check_index(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}	

int	ft_atoi_base(char *str, char *base)
{
	int		posi;
	long	nb;
	int		len;

	nb = 0;
	posi = 1;
	len = ft_check_base(base);
	if (!(len))
		return (0);
	while (*str != '\0' && ft_check_isspace(*str))
		str++;
	while (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			posi = posi * -1;
		str++;
	}
	while (*str != '\0' && ft_check_index(*str, base) != -1)
	{
		nb = nb * len + ft_check_index(*str, base);
		str++;
	}
	return (posi * nb);
}
