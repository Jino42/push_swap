/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:24:41 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/21 00:51:19 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			cut_p_b(t_env *e, int pivot, int grp)
{
	t_pi *pi;

	while (1)
	{
		pi = e->p_b->content;
		if ((pi)->grp != grp)
			return (1);
		if (pi->nb > pivot)
		{
			(pi)->grp = e->cur_grp + 1;
			do_op(e, PA, e->flag);
		}
		else
		{
			(pi)->grp = e->cur_grp + 2;
			do_op(e, RB, e->flag);
		}
		print_pile(e);
	}
	return (1);
}

int			algo_p_b(t_env *e)
{
	int		size;

	size = size_grp(e->p_b);
	if (size <= 3)
		if (case_b(e, size))
			return (1);
	cut_p_b(e,
			find_mediane(e->p_b, size),
			((t_pi*)(e->p_b->content))->grp);
	return (1);
}
