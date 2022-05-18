/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:39:23 by jtaravel          #+#    #+#             */
/*   Updated: 2021/11/02 17:41:21 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_struct
{
	struct s_list *next;
	void	*data;
}	t_list;

t_list	*ft_create_elem(void *data);

#endif
