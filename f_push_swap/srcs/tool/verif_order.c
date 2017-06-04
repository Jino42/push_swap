/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 05:35:47 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 18:47:44 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_order(t_env *e)
{
	t_list	*i;

	if (e->nb_b)
		return (0);
	i = e->p_a;
	while (i->next)
	{
		if (((t_pi*)(i->content))->nb > ((t_pi*)(i->next->content))->nb)
			return (0);
		i = i->next;
	}
	return (1);
}
