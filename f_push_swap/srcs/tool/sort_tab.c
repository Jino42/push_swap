/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 05:17:29 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 22:17:19 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_tab(t_env *e)
{
	int		i;
	t_list	*l;

	l = e->p_a;
	if (!(e->tab = (int*)ft_memalloc(sizeof(int) * e->nb_a)))
		exit(ft_error("Faild Malloc"));
	i = 0;
	while (i < e->nb_a)
	{
		e->tab[i] = ((t_pi*)(l->content))->nb;
		i++;
		l = l->next;
	}
	quick_sort(e->tab, 0, e->nb_arg - 1);
	return (1);
}
