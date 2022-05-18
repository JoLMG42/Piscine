/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:53:04 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/18 13:01:03 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
}
