/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:18:19 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/23 00:22:22 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	trick(t_env *e)
{
	if (e->tab[e->nb_sort] == ((t_pi*)(e->p_a->content))->nb)
	{
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	return (0);
}

static int	come_back(t_env *e, int nb_ra)
{
	while (nb_ra && e->nb_sort)
	{
		do_op(e, RRA, e->flag);
		nb_ra--;
	}
	return (1);
}

static int	cut_p_a(t_env *e, int pivot, int grp)
{
	t_pi	*pi;
	int		nb_ra;

	nb_ra = 0;
	while (1)
	{
		pi = e->p_a->content;
		if (pi->grp != grp)
			return (come_back(e, nb_ra));
		if (pi->nb > pivot)
		{
			pi->grp = e->cur_grp + 1;
			do_op(e, RA, e->flag);
			nb_ra++;
		}
		else
		{
			pi->grp = e->cur_grp + 2;
			do_op(e, PB, e->flag);
		}
	}
	return (1);
}

int			algo_p_a(t_env *e)
{
	int		size;

	if (((t_pi*)(e->p_a->content))->grp == -1)
		return (1);
	size = size_grp(e->p_a);
	if (size <= 3)
	{
		if (case_a(e, size))
			return (1);
	}
	if (trick(e))
		return (1);
	cut_p_a(e,
	find_mediane(e->p_a, size),
	((t_pi*)(e->p_a->content))->grp);
	return (1);
}
