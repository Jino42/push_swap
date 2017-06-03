/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/03 22:21:44 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		make_3choice(t_env *e)
{
	if (NB_1(e->p_a) > NB_2(e->p_a) &&
		NB_2(e->p_a) > NB_3(e->p_a) &&
		NB_1(e->p_a) > NB_3(e->p_a))
	{
		do_op(e, SA, e->flag);
		do_op(e, RRA, e->flag);
	}
	else if (NB_1(e->p_a) > NB_2(e->p_a) &&
			NB_2(e->p_a) < NB_3(e->p_a) &&
			NB_1(e->p_a) > NB_3(e->p_a))
	{
		do_op(e, RA, e->flag);
	}
	else if (NB_1(e->p_a) < NB_2(e->p_a) &&
			NB_2(e->p_a) > NB_3(e->p_a) &&
			NB_1(e->p_a) > NB_3(e->p_a))
	{
		do_op(e, RRA, e->flag);
	}
	else if (NB_1(e->p_a) > NB_2(e->p_a) &&
			NB_2(e->p_a) < NB_3(e->p_a) &&
			NB_1(e->p_a) < NB_3(e->p_a))
	{
		do_op(e, SA, e->flag);
	}
	else if (NB_1(e->p_a) < NB_2(e->p_a) &&
			NB_2(e->p_a) > NB_3(e->p_a) &&
			NB_1(e->p_a) < NB_3(e->p_a))
	{
		do_op(e, SA, e->flag);
		do_op(e, RA, e->flag);
	}
}

int			little_algo(t_env *e)
{
	int		nb_pb = 0;

	while (nb_pb < 2)
	{
		if (NB_1(e->p_a) < e->tab[2])
		{
			do_op(e, PB, e->flag);
			nb_pb++;
		}
		else if (NB_2(e->p_a) >= e->tab[2] && NB_1(e->p_a) < NB_2(e->p_a))
			do_op(e, SA, e->flag);
		else
			do_op(e, RA, e->flag);
	}
	if (NB_1(e->p_b) < NB_2(e->p_b))
		do_op(e, SB, e->flag);
	make_3choice(e);
	do_op(e, PA, e->flag);
	do_op(e, PA, e->flag);
	return (1);
}

int			loop_check(t_env *e)
{
	while (!verif_order(e))
	{
		if (e->nb_arg > 5)
			my_algo(e);
		else
			little_algo(e);
	}
	return (1);
}
