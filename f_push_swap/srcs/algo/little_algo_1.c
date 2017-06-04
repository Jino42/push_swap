/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:47:14 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 20:59:04 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	little_algo_1_next(t_env *e)
{
	if (e->nb_b > 1 &&
			nb_1(e->p_b) > nb_2(e->p_b))
		do_op(e, SB, e->flag);
	else if (e->nb_b && nb_1(e->p_b) == e->tab[e->nb_sort])
	{
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
	}
	else if (((t_pi*)(e->p_a->content))->grp != -1)
		do_op(e, PB, e->flag);
	else
		do_op(e, RB, e->flag);
}

int			little_algo_1(t_env *e)
{
	if (((t_pi*)(ft_lstlast(e->p_a)->content))->grp != 1 &&
			((t_pi*)(ft_lstlast(e->p_a)->content))->nb == e->tab[e->nb_sort])
	{
		((t_pi*)(ft_lstlast(e->p_a)->content))->grp = -1;
		e->nb_sort++;
	}
	else if (nb_1(e->p_a) == e->tab[e->nb_sort])
		do_op(e, RA, e->flag | SORTED);
	else if (e->nb_a > 1 &&
			nb_1(e->p_a) > nb_2(e->p_a) &&
			((t_pi*)(e->p_a->content))->grp != -1 &&
			((t_pi*)(e->p_a->next->content))->grp != -1)
	{
		if (e->nb_b > 1 &&
				nb_1(e->p_b) > nb_2(e->p_b))
			do_op(e, SS, e->flag);
		else
			do_op(e, SA, e->flag);
	}
	else
		little_algo_1_next(e);
	return (1);
}
