/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:43:38 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 14:42:40 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_do_op.h"

void	do_op(char *s1, char *s2, char *s3)
{
	if (*s2 == '+')
		(*addition)(ft_atoi(s1), ft_atoi(s3));
	else if (*s2 == '-')
		(*soustraction)(ft_atoi(s1), ft_atoi(s3));
	else if (*s2 == '*')
		(*multiplication)(ft_atoi(s1), ft_atoi(s3));
	else if (*s2 == '/')
		(*division)(ft_atoi(s1), ft_atoi(s3));
	else if (*s2 == '%')
		(*modulo)(ft_atoi(s1), ft_atoi(s3));
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(av[1], av[2], av[3]);
	return (0);
}
