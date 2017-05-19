/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:18:19 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 01:47:40 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define nb_1(lst) (((t_pi*)(lst->content))->nb)
# define nb_2(lst) (((t_pi*)(lst->next->content))->nb)
# define nb_3(lst) (((t_pi*)(lst->next->next->content))->nb)

int			case_a(t_env *e, int size)
{
	if (size == 1)
	{
		((t_pi*)(e->p_a->content))->grp = -1;
		do_op(e, RA, VERB);
		e->nb_sort++;
	}
	else if (size == 3)
	{
		if (nb_1(e->p_a) < nb_2(e->p_a) &&
			nb_2(e->p_a) < nb_3(e->p_a) &&
			nb_1(e->p_a) < nb_3(e->p_a))
		{
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_a) < nb_2(e->p_a) &&
 				nb_2(e->p_a) > nb_3(e->p_a) &&
				nb_1(e->p_a) < nb_3(e->p_a))
		{
			do_op(e, RA, VERB);
			do_op(e, SA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_a) > nb_2(e->p_a) &&
				nb_2(e->p_a) < nb_3(e->p_a) &&
				nb_1(e->p_a) < nb_3(e->p_a))
		{
			do_op(e, SA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_a) < nb_2(e->p_a) &&
				nb_2(e->p_a) > nb_3(e->p_a) &&
				nb_1(e->p_a) > nb_3(e->p_a))
		{
			do_op(e, PB, VERB);
			do_op(e, SA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_a) > nb_2(e->p_a) &&
				nb_2(e->p_a) > nb_3(e->p_a) &&
				nb_1(e->p_a) > nb_3(e->p_a))
		{
			do_op(e, PB, VERB);
			do_op(e, SA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
			do_op(e, PA, VERB);
			do_op(e, RA, VERB);
		}
		else if (nb_1(e->p_a) > nb_2(e->p_a) &&
				nb_2(e->p_a) < nb_3(e->p_a) &&
				nb_1(e->p_a) > nb_3(e->p_a))
		{
			do_op(e, SA, VERB);
			do_op(e, RA, VERB);
			do_op(e, SA, VERB);
			do_op(e, RA, VERB);
			do_op(e, RA, VERB);
		}
		else
			return (0);
	}
	else
	{
		if (((t_pi*)(e->p_a->content))->nb > ((t_pi*)(e->p_a->next->content))->nb)
			do_op(e, SA, VERB);
		((t_pi*)(e->p_a->content))->grp = -1;
		do_op(e, RA, VERB);
		((t_pi*)(e->p_a->content))->grp = -1;
		do_op(e, RA, VERB);
		e->nb_sort += 2;
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
			while (nb_ra && e->nb_sort)
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
	if (size <= 3)
	{
		if (case_a(e, size))
			return (1);
	}
	cut_p_a(e,
	find_mediane(e->p_a, size),
	((t_pi*)(e->p_a->content))->grp);
	return (1);
}
