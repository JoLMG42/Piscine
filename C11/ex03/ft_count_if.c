/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:41:58 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 14:09:11 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*));

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;

	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) == 0)
			return (0);
		i++;
	}
	return (i);
}
