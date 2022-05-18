/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:56:34 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/20 20:33:10 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printable(char c)
{
	if (c < ' ' || c == 127)
		return (0);
	return (1);
}

void	ft_hexaconv(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar(("0123456789abcdef")[c / 16]);
	ft_putchar(("0123456789abcdef")[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_printable(str[i]))
			ft_putchar(str[i]);
		else
			ft_hexaconv(str[i]);
		i++;
	}
}
#include <unistd.h>


void	ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	write(1, str, l);
}

int		main()
{
	char c[] = "Coucou\ntu vas\x81 bien ?";
	ft_putstr_non_printable(c);
}
