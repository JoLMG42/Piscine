/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:24:51 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 11:28:50 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}
