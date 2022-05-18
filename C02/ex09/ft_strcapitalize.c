/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:38:40 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/19 14:26:15 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		while (str[i] < 'a' && str[i] > 'z')
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			i++;
		}	
		while ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
			i++;
		i++;
	}
	return (str);
}
