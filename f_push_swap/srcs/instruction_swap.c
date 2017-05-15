/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:32:31 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/15 23:59:24 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		op_sa(t_env *e)
{
	if (e->nb_a > 1)
		SWAP(*(int*)(e->p_a->content), *(int*)(e->p_a->next->content));
	return (1);
}

int		op_sb(t_env *e)
{
	if (e->nb_b > 1)
		SWAP(*(int*)(e->p_b->content), *(int*)(e->p_b->next->content));
	return (1);
}

int		op_ss(t_env *e)
{
	if (op_sa(e) && op_sb(e))
		return (1);
	return (0);
}
