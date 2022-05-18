/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:33:16 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/19 09:42:52 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_print_combn(int n);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_combn(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(n - 1 + '0');
		ft_putchar(n + '0');
		ft_putchar(n + 1 + '0');
		if (n != 7)
			write(1, ", ", 2);
		i++;
		n++;
	}
}

int	main()
{
	ft_print_combn(3);
}
	
