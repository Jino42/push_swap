/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 00:40:39 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/21 00:55:43 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verif_3_arg_3(t_env *e)
{
	if (nb_1(e->p_b) > nb_2(e->p_b) && nb_2(e->p_b) < nb_3(e->p_b) &&
			nb_1(e->p_b) < nb_3(e->p_b))
	{
		do_op(e, SB, e->flag);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	else if (nb_1(e->p_b) < nb_2(e->p_b) && nb_2(e->p_b) > nb_3(e->p_b) &&
			nb_1(e->p_b) > nb_3(e->p_b))
	{
		do_op(e, PA, e->flag);
		do_op(e, SB, e->flag);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	return (0);
}

static int	verif_3_arg_2(t_env *e)
{
	if (nb_1(e->p_b) < nb_2(e->p_b) && nb_2(e->p_b) < nb_3(e->p_b) &&
			nb_1(e->p_b) < nb_3(e->p_b))
	{
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	else if (nb_1(e->p_b) > nb_2(e->p_b) && nb_2(e->p_b) < nb_3(e->p_b) &&
			nb_1(e->p_b) > nb_3(e->p_b))
	{
		do_op(e, SB, e->flag);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, SB, e->flag);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	return (verif_3_arg_3(e));
}

static int	verif_3_arg(t_env *e)
{
	if (nb_1(e->p_b) > nb_2(e->p_b) && nb_2(e->p_b) > nb_3(e->p_b) &&
			nb_1(e->p_b) > nb_3(e->p_b))
	{
		do_op(e, PA, e->flag);
		do_op(e, SB, e->flag);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	else if (nb_1(e->p_b) < nb_2(e->p_b) && nb_2(e->p_b) > nb_3(e->p_b) &&
			nb_1(e->p_b) < nb_3(e->p_b))
	{
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, SB, e->flag);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		return (1);
	}
	return (verif_3_arg_2(e));
}

int			case_b(t_env *e, int size)
{
	if (size == 1)
	{
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
	}
	else if (size == 3)
	{
		if (!verif_3_arg(e))
			return (0);
	}
	else
	{
		if (nb_1(e->p_b) > nb_2(e->p_b))
			do_op(e, SB, e->flag);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
	}
	return (1);
}
