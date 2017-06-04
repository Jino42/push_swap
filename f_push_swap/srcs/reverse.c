/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:46:34 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 01:49:44 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	r_come_back(t_env *e, int nb_rb)
{
	while (nb_rb)
	{
		do_op(e, RB, e->flag);
		nb_rb--;
	}
	return (1);
}

static int	r_cut_p_a(t_env *e, int pivot, int grp)
{
	t_pi	*pi;
	int		nb_rb;

	nb_rb = 0;
	ft_printf("Pivot : %i\n", pivot);
	while (e->nb_a)
	{
		pi = e->p_a->content;
		if (pi->grp != grp)
			return (r_come_back(e, nb_rb));
		if (pi->nb < pivot)
		{
			pi->grp = e->cur_grp + 1;
			do_op(e, RA, e->flag);
		}
		else
		{
			nb_rb++;
			pi->grp = e->cur_grp + 2;
			do_op(e, PB, e->flag);
		}
	}
	return (r_come_back(e, nb_rb));
}

int			r_p_a(t_env *e)
{
	int		size;

	if (((t_pi*)(e->p_a->content))->grp == -1)
		return (1);
	size = size_grp(e->p_a);
	//if (trick(e))
	//	return (1);
	r_cut_p_a(e,
			find_mediane(e->p_a, size),
			((t_pi*)(e->p_a->content))->grp);
	return (1);
}

int			r_p_b(t_env *e)
{
	(void)e;
	return (1);
}

int			reverse(t_env *e)
{
	if (e->nb_a && ((t_pi*)(e->p_a->content))->grp != -1)
	{
		ft_printf("Lol %i \n", ((t_pi*)(e->p_a->content))->grp);
		r_p_a(e);
	}
	else
		r_p_b(e);
	e->cur_grp += 3;
	return (1);
}
