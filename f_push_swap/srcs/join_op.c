/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 01:28:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 03:01:11 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define op_1(lst) (*(int*)(lst->content))
# define op_2(lst) (*(int*)(lst->next->content))

int		join_op(t_env *e)
{
	int		final_nb;
	int		op;
	t_list	*lst;

	lst = e->solve;
	final_nb = 0;
	while (lst->next)
	{
		//ft_printf("%s | %s\n", e->op[op_1(lst)], e->op[op_2(lst)]);
		if (op_1(lst) == SA && op_2(lst) == SB)
			op = SS;
		else if (op_1(lst) == RA && op_2(lst) == RB)
			op = RR;
		else if (op_1(lst) == RRA && op_2(lst) == RRB)
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
