/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/21 00:32:03 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			my_algo(t_env *e)
{
	if (!e->nb_b)
		algo_p_a(e);
	else
		algo_p_b(e);
	e->cur_grp += 3;
	return (1);
}

int			loop_check(t_env *e)
{
	while (!verif_order(e))
	{
		my_algo(e);
		ft_printf("Pile A : ");
		print_list(e->p_a);
		ft_printf("Pile B : ");
		print_list(e->p_b);
		ft_printf("[%i]\n", e->nb_op);
	}
	return (1);
}
