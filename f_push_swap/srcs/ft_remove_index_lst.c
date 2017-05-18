/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_index_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 21:17:35 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/18 00:34:10 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_remove_index_lst(t_list **l, size_t size, void (*f)(void *, size_t))
{
	size_t	i;
	t_list	*lst_past;
	t_list	*tmp;
	t_list	*lst;

	lst_past = 0;
	i = 0;
	lst = (*l);
	while (lst)
	{
		if (i == size)
		{
			tmp = lst;
			if (lst_past)
				lst_past->next = lst->next;
			if (i == 0)
				*l = (*l)->next;
			ft_lstdelone(&tmp, f);
			return ;
		}
		i++;
		lst_past = lst;
		lst = lst->next;
	}
}
