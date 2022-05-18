/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_do_op.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:38:38 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 11:03:06 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DO_OP_H

# define LIB_DO_OP_H

# include <unistd.h>

void	do_op(char *s1, char *s2, char *s3);
void	modulo(int a, int b);
void	division(int a, int b);
void	soustraction(int a, int b);
void	multiplication(int a, int b);
void	addition(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
#endif
