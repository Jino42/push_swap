/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:41:12 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 03:35:33 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_mediane(t_list *l, int size)
{
	int tab[size];
	int i, j;

	i = 0;
	while (i < size)
	{
		tab[i] = ((t_pi*)(l->content))->nb;
		i++;
		l = l->next;
	}
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
	return (tab[i / 2]);
}
