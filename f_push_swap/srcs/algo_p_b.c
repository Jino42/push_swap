/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:24:41 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 00:29:29 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			case_b(t_env *e, int size)
{
	if (size == 1)
	{
		((t_pi*)(e->p_b->content))->grp = -1;
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
	}
	else
	{
		if (((t_pi*)(e->p_b->content))->nb > ((t_pi*)(e->p_b->next->content))->nb)
		{
			e->exec[SB](e);
			ft_printf("%s\n", e->op[SB]);
			e->nb_op++;
		}
		((t_pi*)(e->p_b->content))->grp = -1;
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
		((t_pi*)(e->p_b->content))->grp = -1;
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
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
	if (size <= 2)
	{
		case_b(e, size);
		return (1);
	}
	cut_p_b(e,
			find_mediane(e->p_b, size),
			((t_pi*)(e->p_b->content))->grp);
	return (1);
}
