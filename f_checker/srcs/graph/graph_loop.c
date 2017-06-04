/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:40:28 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 23:04:16 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	graph_loop_go(t_env *e, t_list *lst)
{
	if (e->go)
	{
		if (e->cur < e->nb_op)
		{
			if (e->cur >= 0)
				e->exec[*((int*)(lst->content))](e);
			e->cur++;
		}
	}
	else
	{
		if (e->one_up != 0)
		{
			ft_printf("Op [%i / %i]\n", e->cur + 1, e->nb_op);
			ft_printf("%s\n", e->op[*((int*)(lst->content))]);
			if (e->one_up == 1)
				e->exec[*((int*)(lst->content))](e);
			else
				e->exec_neg[*((int*)(lst->content))](e);
		}
	}
}

int			graph_loop(t_env *e)
{
	t_list		*lst;
	int			i;

	i = 0;
	lst = e->solve;
	while (i < e->cur)
	{
		i++;
		lst = lst->next;
	}
	if (e->neg)
	{
		e->cur--;
		e->neg = 0;
	}
	graph_loop_go(e, lst);
	e->one_up = 0;
	graph_aff(e);
	return (1);
}
