/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:09:34 by jtaravel          #+#    #+#             */
/*   Updated: 2021/10/31 14:30:24 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_aff(char *str);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;
	int	len;

	if (*to_find == '0')
		return (0);
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
			{
				ft_aff(&str[i]);
				return (&str[i]);
			}
			n++;
		}
		i++;
	}
	return (0);
}

char	*ft_strstr_for_zero(char *str, char *to_find)
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
			{
				ft_aff(&str[i]);
				return (&str[i]);
			}
			n++;
		}
		i++;
	}
	return (0);
}

void	ft_aff(char *str)
{
	int	i;
	char	s[100];
	int	k;

	k = 0;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == ':')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\n')
	{
		s[k] = str[i];
		k++;
		i++;
	}
	s[k] = '\0';
	ft_putstr(s);
}

/*
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;
	char	s[100];
	int	k;
	
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				if (str[i - j + 1] < '0' || str[i + j + 1] > '9')
				{
					while (str[i] >= '0' && str[i] <= '9')
						i++;
					while (str[i] == ' ' || str[i] == '\t')
						i++;
					if (str[i] == ':')
						i++;
					while (str[i] == ' ' || str[i] == '\t')
						i++;
					while (str[i] != '\n' && ft_check(str, i))
					{
						s[k] = str[i];
						k++;
						i++;
					}
					
					s[k] = '\0';
					ft_putstr(s);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
			
}
*/

char	*size_dico(int fd)
{
	int	i;
	char	buff[4096];
	int	ret;
	char	*tab;

	i = 0;
	ret = read(fd, buff, 4096);
	tab = malloc(sizeof(char) * (ret + 1));
	tab[ret] = '\0';
	while (buff[i])
	{
		tab[i] = buff[i];
		i++;
	}
	return (tab);
}

/*
void	print_tab(char	*tab)
{
	int	i;


	i = 0;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
}
*/

void	ft_calcul_lenght(char *tab, char *str);

void	ft_test(char *tab, char *str)
{
	char	*s;
	int	i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(char) *(ft_strlen(str) + 1));
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (ft_strlen(str) == 3)
	{
		s[i] = '1';
		s[i + 1] = '0';
		s[i + 2] = '0';
		s[i + 3] = '\0';
	}
	s2[0] = str[0];
	s2[1] = '\0';
	ft_strstr(tab, s2);
	write(1, " ", 1);
	ft_strstr(tab, s);
	write(1, " ", 1);
	str[0] = str[1];
	str[1] = str[2];
	str[2] = '\0';
	ft_calcul_lenght(tab, str);
}

void	ft_test2(char *tab, char *str)
{
	char	*s;
	int	i;
	
	i = 0;
	s = malloc(sizeof(char) * (ft_strlen(str) + i));
	s[i] = str[i];
	if (ft_strlen(str) == 2)
	s[i + 1] = '0';
	s[i + 2] = '\0';
	str[0] = str[1];
	str[1] = '\0';
	ft_strstr(tab, s);
	write(1, " ", 1);
	ft_strstr(tab, str);
}


void	ft_millier(char *tab, char *str)
{
	char	*s;
	int	i;
	char	s2[1];

	i = 1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	s2[0] = str[0];
	while (ft_strlen(str) == 4 && i < ft_strlen(str))
	{
		s[0] = '1';
		s[i] = '0';
		str[i - 1] = str[i];
		i++;
	}
	s[i] = '\0';
	str[i - 1] = '\0';
	ft_strstr(tab, s2);
	write(1, " ", 1);
	ft_strstr(tab, s);
	write(1, " ", 1);
	ft_calcul_lenght(tab ,str);
}

void	ft_10millier(char *tab, char *str)
{
	char	*s;
	int	i;
	char	s2[2];

	i = 1;
	s2[0] = str[0];
	s2[1] = str[1];
	s = malloc(sizeof(char) * ft_strlen(str));
	while (ft_strlen(str) == 5 && i < ft_strlen(str))
	{
		s[0] = '1';
		s[i] = '0';
		str[i - 1] = str[i];
		i++;
	}
	s[i - 1] = '\0';
	str[i - 2] = '\0';
	ft_calcul_lenght(tab, s2);
	write(1, " ", 1);
	ft_strstr(tab, s);
	write(1, " ", 1);
	ft_calcul_lenght(tab, str);
}

void	ft_calcul_lenght(char *tab, char *str)
{
	if (ft_strlen(str) == 1 && *str == '0')
		ft_strstr_for_zero(tab, str);
	else if (ft_strlen(str) == 1 && *str != '0')
		ft_strstr(tab, str);
	else if (ft_strlen(str) == 2 && *str == '1')
		ft_strstr(tab, str);
	else if (ft_strlen(str) == 2 && str[0] != '1')
		ft_test2(tab, str);
	else if (ft_strlen(str) == 3 && *str != '0')
		ft_test(tab, str);
	else if (ft_strlen(str) == 4)
		ft_millier(tab, str);
	else if (ft_strlen(str) == 5)
		ft_10millier(tab, str);


}
		
		


int main(int ac, char **av)
{
	int	fd;
	char	*tab;
	int	i;

	if (ac > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	i = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	tab = size_dico(fd);
/*	if (ft_strlen(av[1]) >= 4 && ft_strlen(av[1]) <= 6)
		ft_millier(tab, av[1]);*/
	ft_calcul_lenght(tab, av[1]);
//	ft_strstr(tab, av[1]);
//	print_tab(tab);
	return (0);
}

