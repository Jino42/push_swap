/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:51:15 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 21:28:55 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_op(t_env *e, int op, char flag)
{
	if (flag & SORTED)
	{
		((t_pi*)(e->p_a->content))->grp = -1;
		e->nb_sort++;
	}
	e->exec[op](e);
	ft_lstinsert(&e->solve, ft_lstnew(&op, sizeof(int*)));
	e->nb_op++;
	if (e->flag & FLAG_V)
	{
		print_pile(e);
		ft_printf("%s\n", e->op[op]);
	}
}
