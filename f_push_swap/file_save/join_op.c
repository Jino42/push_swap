/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 01:28:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/21 01:08:45 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		join_op(t_env *e)
{
	int		final_nb;
	int		op;
	t_list	*lst;

	if (!e->solve)
		return (1);
	lst = e->solve;
	final_nb = 0;
	while (lst->next)
	{
		if (OP_1(lst) == SA && OP_2(lst) == SB)
			op = SS;
		else if (OP_1(lst) == RA && OP_2(lst) == RB)
			op = RR;
		else if (OP_1(lst) == RRA && OP_2(lst) == RRB)
			op = RRR;
		else
			op = (*(int*)(lst->content));
		ft_lstinsert(&e->final_solve, ft_lstnew(&op, sizeof(int*)));
		lst = lst->next;
		final_nb++;
	}
	ft_lstinsert(&e->final_solve, ft_lstnew(((int*)(lst->content)), sizeof(int*)));
	final_nb++;
	ft_printf("FINAL  : %i\n", final_nb);
	return (1);
}
