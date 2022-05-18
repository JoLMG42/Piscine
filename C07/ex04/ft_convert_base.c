/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 10:58:03 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/01 10:57:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_pos(char *str, char c);
int		ft_check_isspace(char c);
int		ft_strlen(char *str);
int		ft_check_base(char *str);

int	ft_size(int nbr, int base_size)
{
	int	size;

	size = 0;
	if (nbr <= 0)
	{
		size++;
		nbr = nbr * -1;
	}
	while (nbr != 0)
	{
		size++;
		nbr = nbr / base_size;
	}
	return (size);
}

char	*ft_itoa_base(int nbr, char *base_to, int base_size)
{
	long	nb;
	int		len;
	char	*res;
	int		i;

	nb = nbr;
	len = ft_size(nbr, base_size);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (nb == 0)
		res[0] = base_to[0];
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	i = len;
	while (nb > 0)
	{
		res[--i] = base_to[nb % base_size];
		nb = nb / base_size;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	char	*res;
	int		base_size_to;
	int		base_size_from;
	int		posi;

	if (nbr == 0 || base_from == 0 || base_to == 0)
		return (0);
	base_size_to = ft_check_base(base_to);
	base_size_from = ft_check_base(base_from);
	if (!ft_check_base(base_from) || !base_size_to)
		return (0);
	while (*nbr && (ft_check_isspace(*nbr) == 1))
		nbr++;
	posi = 1;
	while (*nbr && (*nbr == '+' || *nbr == '-'))
		if (*nbr++ == '-')
			posi = -posi;
	nb = 0;
	while (*nbr && (ft_pos(base_from, *nbr) != -1))
		nb = nb * base_size_from + ft_pos(base_from, *nbr++);
	res = ft_itoa_base((posi * nb), base_to, base_size_to);
	return (res);
}
