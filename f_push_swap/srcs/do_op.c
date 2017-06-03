/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:51:15 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/23 00:22:15 by ntoniolo         ###   ########.fr       */
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
	ft_printf("%s\n", e->op[op]);
	ft_lstinsert(&e->solve, ft_lstnew(&op, sizeof(int*)));
	if (e->flag & FLAG_V)
		print_pile(e);
	e->nb_op++;
}
