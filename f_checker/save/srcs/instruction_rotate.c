/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 21:38:38 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/15 21:52:21 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		op_ra(t_env *e)
{
	if (e->nb_a > 1)
	{
		ft_lstinsert(&e->p_a, ft_lstnew(&(*(int*)(e->p_a->content)), sizeof(int)));
		ft_remove_index_lst(&e->p_a, 0, &del_lst_pile);
	}
	return (1);
}

int		op_rb(t_env *e)
{
	if (e->nb_b > 1)
	{
		ft_lstinsert(&e->p_b, ft_lstnew(&(*(int*)(e->p_b->content)), sizeof(int)));
		ft_remove_index_lst(&e->p_b, 0, &del_lst_pile);
	}
	return (1);
}

int		op_rr(t_env *e)
{
	if (op_ra(e) && op_rb(e))
		return (1);
	return (0);
}
