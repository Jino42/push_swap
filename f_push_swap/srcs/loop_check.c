/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/16 01:56:19 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int verif_order(t_env *e)
{
	t_list	*i;

	if (e->nb_b)
		return (0);
	i = e->p_a;
	while (i->next)
	{
		if (*(int*)(i->content) > *(int*)(i->next->content))
			return (0);
		i = i->next;
	}
	return (1);
}

int			algo(t_env *e)
{
	static int in_a = 1;

	if (!e->nb_a)
		in_a = 0;
	if (!e->nb_b)
		in_a = 1;
	/*if (e->nb_b > 2 &&
		ft_abs((*(int*)(e->p_b->content)) - (*(int*)((ft_lstlast(e->p_b))->content))) <
		ft_abs((*(int*)(e->p_b->content)) - (*(int*)(e->p_b->next->content))))
	{
		e->exec[RB](e);
		ft_printf("%s\n", e->op[RB]);
	}
	else*/if (e->nb_b > 1 && (*(int*)(e->p_b->content)) < (*(int*)((ft_lstlast(e->p_b))->content)))
	{
		e->exec[RB](e);
		ft_printf("%s\n", e->op[RB]);
	}
	else if (e->nb_a && (*(int*)((ft_lstlast(e->p_a))->content)) < (*(int*)(e->p_a->content)))
	{
		e->exec[RRA](e);
		ft_printf("%s\n", e->op[SA]);
	}
	else if (e->nb_a > 1 && (*(int*)(e->p_a->content)) > (*(int*)(e->p_a->next->content)))
	{
		e->exec[SA](e);
		ft_printf("%s\n", e->op[SA]);
	}
	else if (e->nb_a && in_a)
	{
		e->exec[PB](e);
		ft_printf("%s\n", e->op[PB]);
	}
	else
	{
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
	}
	return (1);
}

int			loop_check(t_env *e)
{
	int i;

	i = 0;
	while (!verif_order(e))
	{
		i++;
		algo(e);
		ft_printf("Pile A : ");
		print_list(e->p_a);
		ft_printf("Pile B : ");
		print_list(e->p_b);
		ft_printf("[%i]\n", i);
	}
	return (1);
}
