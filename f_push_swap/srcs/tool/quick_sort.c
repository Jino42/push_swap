/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 22:15:18 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 00:53:40 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *tab, int a, int b)
{
	int tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void			quick_sort(int *tab, int start, int end)
{
	int left;
	int right;
	int pivot;

	left = start;
	right = end;
	if (start >= end)
		return ;
	pivot = tab[start];
	while (1)
	{
		while (tab[right] > pivot)
			right--;
		while (tab[left] < pivot)
			left++;
		if (left < right)
			swap(tab, left, right);
		else
			break ;
	}
	quick_sort(tab, start, right);
	quick_sort(tab, right + 1, end);
}
