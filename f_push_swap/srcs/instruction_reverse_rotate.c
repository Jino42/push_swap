/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 21:46:26 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/16 00:00:44 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		op_rra(t_env *e)
{
	t_list	*lst;

	if (e->nb_a > 1)
	{
		lst = ft_lstlast(e->p_a);
		ft_lstadd(&e->p_a, ft_lstnew(&(*(int*)(lst->content)), sizeof(int)));
		ft_remove_index_lst(&e->p_a, e->nb_a, &del_lst_pile);
	}
	return (1);
}

int		op_rrb(t_env *e)
{
	t_list	*lst;

	if (e->nb_b > 1)
	{
		lst = ft_lstlast(e->p_b);
		ft_lstadd(&e->p_b, ft_lstnew(&(*(int*)(lst->content)), sizeof(int)));
		ft_remove_index_lst(&e->p_b, e->nb_b, &del_lst_pile);
	}
	return (1);
}

int		op_rrr(t_env *e)
{
	if (op_rra(e) && op_rrb(e))
		return (1);
	return (0);
}
