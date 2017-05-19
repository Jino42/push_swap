/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 01:28:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 01:53:40 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define op_1(lst) (*(int*)(lst->content))
# define op_2(lst) (*(int*)(lst->next->content))

int		join_op(t_env *e)
{
	int		final_nb;
	t_list	*lst;

	final_nb = 0;
	while (lst->next)
	{
		if (op_1(lst) == SA && op_2(lst) == SB)
			;
		lst = lst->next;
		final_nb++;
	}
}
