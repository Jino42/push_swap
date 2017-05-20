/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 00:39:59 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/21 01:09:13 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		verif_3_arg_3(t_env *e)
{
	if (NB_1(e->p_a) > NB_2(e->p_a) &&
			NB_2(e->p_a) > NB_3(e->p_a) &&
			NB_1(e->p_a) > NB_3(e->p_a))
	{
		do_op(e, PB, e->flag);
		do_op(e, SA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	else if (NB_1(e->p_a) > NB_2(e->p_a) &&
			NB_2(e->p_a) < NB_3(e->p_a) &&
			NB_1(e->p_a) > NB_3(e->p_a))
	{
		do_op(e, SA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, SA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	return (0);
}

static int		verif_3_arg_2(t_env *e)
{
	if (NB_1(e->p_a) > NB_2(e->p_a) &&
			NB_2(e->p_a) < NB_3(e->p_a) &&
			NB_1(e->p_a) < NB_3(e->p_a))
	{
		do_op(e, SA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	else if (NB_1(e->p_a) < NB_2(e->p_a) &&
			NB_2(e->p_a) > NB_3(e->p_a) &&
			NB_1(e->p_a) > NB_3(e->p_a))
	{
		do_op(e, PB, e->flag);
		do_op(e, SA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	return (verif_3_arg_3(e));
}

static int		verif_3_arg(t_env *e)
{
	if (NB_1(e->p_a) < NB_2(e->p_a) &&
			NB_2(e->p_a) < NB_3(e->p_a) &&
			NB_1(e->p_a) < NB_3(e->p_a))
	{
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	else if (NB_1(e->p_a) < NB_2(e->p_a) &&
			NB_2(e->p_a) > NB_3(e->p_a) &&
			NB_1(e->p_a) < NB_3(e->p_a))
	{
		do_op(e, RA, e->flag | SORTED);
		do_op(e, SA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	else
		return (verif_3_arg_2(e));
	return (0);
}

int				case_a(t_env *e, int size)
{
	if (size == 1)
		do_op(e, RA, e->flag | SORTED);
	else if (size == 3)
	{
		if (!(verif_3_arg(e)))
			return (0);
	}
	else
	{
		if (NB_1(e->p_a) > NB_2(e->p_a))
			do_op(e, SA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
	}
	return (1);
}
