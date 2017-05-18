/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:18:19 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 00:25:13 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			case_a(t_env *e, int size)
{
	if (size == 1)
	{
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[PA]);
		e->nb_op++;
	}
	else
	{
		if (((t_pi*)(e->p_a->content))->nb > ((t_pi*)(e->p_a->next->content))->nb)
		{
			e->exec[SA](e);
			ft_printf("%s\n", e->op[SA]);
			e->nb_op++;
		}
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
	}
	return (1);
}

int			cut_p_a(t_env *e, int pivot, int grp)
{
	t_pi	*pi;
	int		nb_ra;

	nb_ra = 0;
	while (1)
	{
		pi = e->p_a->content;
		if ((pi)->grp != grp)
		{
			while (nb_ra)
			{
				do_op(e, RRA, VERB);
				nb_ra--;
			}
			return (1);
		}
		if (pi->nb > pivot)
		{
			(pi)->grp = e->cur_grp + 1;
			do_op(e, RA, VERB);
			nb_ra++;
		}
		else
		{
			(pi)->grp = e->cur_grp + 2;
			do_op(e, PB, VERB);
		}
		print_pile(e);
	}
	return (1);
}

/*
** If size_grp < 2
**     Complete quest
** else
**     quick_sort
*/
int			algo_p_a(t_env *e)
{
	int		size;

	size = size_grp(e->p_a);
	if (size <= 2)
	{
		case_a(e, size);
		return (1);
	}
	cut_p_a(e,
	find_mediane(e->p_a, size),
	((t_pi*)(e->p_a->content))->grp);
	return (1);
}
