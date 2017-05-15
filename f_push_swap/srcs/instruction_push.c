/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:04:51 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/16 01:09:35 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		op_pb(t_env *e)
{
	if (e->nb_a)
	{
		ft_lstadd(&e->p_b, ft_lstnew(&(*(int*)(e->p_a->content)), sizeof(int)));
		ft_remove_index_lst(&e->p_a, 0, &del_lst_pile);
		e->nb_b++;
		e->nb_a--;
	}
	return (1);
}

int		op_pa(t_env *e)
{
	if (e->nb_b)
	{
		ft_lstadd(&e->p_a, ft_lstnew(&(*(int*)(e->p_b->content)), sizeof(int)));
		ft_remove_index_lst(&e->p_b, 0, &del_lst_pile);
		e->nb_b--;
		e->nb_a++;
	}
	return (1);
}
