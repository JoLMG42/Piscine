/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:43:18 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/28 14:53:22 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_print_memory(void *addr, unsigned int size);
int	ft_printable(char c);

void	ft_printf_norm(char *str)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		j = 17;
		while (j >= 0)
		{	
			if (ft_printable(str[i]))
			{
				write(1, &str[i], 1);
				j--;
				i++;
			}
			if (j == 0)
				write(1, "\n", 1);
		}
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printable(char c)
{
	if (c < 32 && c > 126)
		return (0);
	return (1);
}

void	ft_hexaconv(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar(("0123456789abcdef")[c / 16]);
	ft_putchar(("0123456789abcdef")[c % 16]);
}
	


void	*ft_print_memory(void *addr, unsigned int size)
{	
	int	i;
	char	*s;
	i = 0;
	s = addr;
	ft_printf_norm(addr);
	while (s[i])
	{
		ft_hexaconv(s[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	ft_printf_norm("Bonjour les amin\nches...c est fo\nu.tout.ce qu on\npeut faire avec.\n..print_memory..\n..lol.lol. .");

}


