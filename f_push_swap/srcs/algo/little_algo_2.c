/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:47:55 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 17:49:54 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			little_algo_2(t_env *e)
{
	if (find_place(e, e->tab[0]) > e->nb_arg / 2 &&
			((t_pi*)(ft_lstlast(e->p_a)->content))->grp != -1 &&
			((t_pi*)(e->p_a->content))->nb != e->tab[e->nb_sort])
		do_op(e, RA, e->flag);
	else if (((t_pi*)(ft_lstlast(e->p_a)->content))->grp != -1 &&
			((t_pi*)(ft_lstlast(e->p_a)->content))->nb != e->tab[e->nb_sort])
		do_op(e, RRA, e->flag);
	else if (((t_pi*)(ft_lstlast(e->p_a)->content))->grp != -1 &&
			((t_pi*)(ft_lstlast(e->p_a)->content))->nb == e->tab[e->nb_sort])
	{
		((t_pi*)(ft_lstlast(e->p_a)->content))->grp = -1;
		e->nb_sort++;
	}
	else if (NB_1(e->p_a) == e->tab[e->nb_sort])
	{
		do_op(e, RA, e->flag | SORTED);
	}
	else if (e->nb_a > 1 &&
			NB_1(e->p_a) > NB_2(e->p_a) &&
			((t_pi*)(e->p_a->content))->grp != -1 &&
			((t_pi*)(e->p_a->next->content))->grp != -1)
	{
		if (e->nb_b > 1 &&
				NB_1(e->p_b) > NB_2(e->p_b))
			do_op(e, SS, e->flag);
		else
			do_op(e, SA, e->flag);
	}
	else if (e->nb_b > 1 &&
			NB_1(e->p_b) > NB_2(e->p_b))
		do_op(e, SB, e->flag);
	else if (e->nb_b && NB_1(e->p_b) == e->tab[e->nb_sort])
	{
		do_op(e, PA, e->flag);
		do_op(e, RA, e->flag | SORTED);
	}
	else if (((t_pi*)(e->p_a->content))->grp != -1)
		do_op(e, PB, e->flag);
	else
		do_op(e, RB, e->flag);
	return (1);
}
