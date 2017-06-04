/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:32:31 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/21 01:09:56 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		op_sa(t_env *e)
{
	if (e->nb_a > 1)
	{
		SWAP(NB_1(e->p_a), NB_2(e->p_a));
		SWAP(((t_pi*)(e->p_a->content))->grp,
			((t_pi*)(e->p_a->next->content))->grp);
	}
	return (1);
}

int		op_sb(t_env *e)
{
	if (e->nb_b > 1)
	{
		SWAP(NB_1(e->p_b), NB_2(e->p_b));
		SWAP(((t_pi*)(e->p_b->content))->grp,
				((t_pi*)(e->p_b->next->content))->grp);
	}
	return (1);
}

int		op_ss(t_env *e)
{
	if (op_sa(e) && op_sb(e))
		return (1);
	return (0);
}
