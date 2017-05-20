/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:41:12 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/21 01:03:39 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bubble_sort(int size, int tab[size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				SWAP(tab[i], tab[j]);
				i = 0;
			}
			j++;
		}
		i++;
	}
	return (1);
}

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
	bubble_sort(size, tab);
	return (tab[i / 2]);
}
