/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:29:28 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/19 17:04:00 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;
	int	len;

	len = ft_strlen(to_find);
	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i + n] == to_find[n])
		{
			if (n == len - 1)
				return (&str[i]);
			n++;
		}
		i++;
	}
	return (0);
}
