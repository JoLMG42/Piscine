/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:04:35 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/03 11:24:33 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_string_tab(char **tab);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[j]) < 0)
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
