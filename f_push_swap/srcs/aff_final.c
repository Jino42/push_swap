/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:23:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 18:23:48 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		aff_final(t_env *e)
{
	t_list *l;
	int		i;

	i = 0;
	while (i < NB_ALGO)
	{
		l = e->final_solve[i];
		ft_printf("\nAlgo %i : [%i]\n", i, e->res[i]);
		while (l)
		{
			ft_printf("%4s-", e->op[*((int*)(l->content))]);
			l = l->next;
		}
		i++;
	}
}
