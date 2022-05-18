/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:35:31 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/02 17:50:25 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list *ft_create_elem(void *data);

t_list *ft_create_elem(void *data)
{
	t_list *elem;
	

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->next = NULL;
	elem->data = data;
	printf("%p\n", data);
	return (elem);
}

int main(void)
{
	ft_create_elem("pop");
}
