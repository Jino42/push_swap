/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:24:41 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 03:55:47 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			case_b(t_env *e, int size)
{
	if (size == 1)
	{
		((t_pi*)(e->p_b->content))->grp = -1;
		do_op(e, PA, VERB);
		do_op(e, RA, VERB);
		e->nb_sort++;
	}
	else if (size == 3)
	{
		if (nb_1(e->p_b) < nb_2(e->p_b) &&
			nb_2(e->p_b) < nb_3(e->p_b) &&
			nb_1(e->p_b) < nb_3(e->p_b))
		{
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_b) < nb_2(e->p_b) &&
				nb_2(e->p_b) > nb_3(e->p_b) &&
				nb_1(e->p_b) < nb_3(e->p_b))
		{
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, SB, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_b) > nb_2(e->p_b) &&
				nb_2(e->p_b) < nb_3(e->p_b) &&
				nb_1(e->p_b) < nb_3(e->p_b))
		{
			do_op(e, SB, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_b) < nb_2(e->p_b) &&
				nb_2(e->p_b) > nb_3(e->p_b) &&
				nb_1(e->p_b) > nb_3(e->p_b))
		{
			do_op(e, PA, VERB);
			do_op(e, SB, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_b) > nb_2(e->p_b) &&
				nb_2(e->p_b) > nb_3(e->p_b) &&
				nb_1(e->p_b) > nb_3(e->p_b))
		{
			do_op(e, PA, VERB);
			do_op(e, SB, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_b) > nb_2(e->p_b) &&
				nb_2(e->p_b) < nb_3(e->p_b) &&
				nb_1(e->p_b) > nb_3(e->p_b))
		{
			do_op(e, SB, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, SB, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
		}
		else
			return (0);
	}
	else
	{
		if (((t_pi*)(e->p_b->content))->nb > ((t_pi*)(e->p_b->next->content))->nb)
			do_op(e, SB, VERB);
		((t_pi*)(e->p_b->content))->grp = -1;
		do_op(e, PA, VERB);
		do_op(e, RA, VERB);
		((t_pi*)(e->p_b->content))->grp = -1;
		do_op(e, PA, VERB);
		do_op(e, RA, VERB);
		e->nb_sort += 2;
	}
	return (1);
}

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
			do_op(e, PA, VERB);
		}
		else
		{
			(pi)->grp = e->cur_grp + 2;
			do_op(e, RB, VERB);
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
	{
		case_b(e, size);
		return (1);
	}
	cut_p_b(e,
			find_mediane(e->p_b, size),
			((t_pi*)(e->p_b->content))->grp);
	return (1);
}
