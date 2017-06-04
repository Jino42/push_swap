/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:41:12 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 22:19:16 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_mediane(t_list *l, int size)
{
	int tab[size];
	int i;

	i = 0;
	while (i < size)
	{
		tab[i] = ((t_pi*)(l->content))->nb;
		i++;
		l = l->next;
	}
	quick_sort(tab, 0, size - 1);
	return (tab[i / 2]);
}
