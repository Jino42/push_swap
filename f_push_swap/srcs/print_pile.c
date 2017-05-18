/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:54:53 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/18 23:55:55 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_pile(t_env *e)
{
	ft_printf("Pile A : ");
	print_list(e->p_a);
	ft_printf("Pile B : ");
	print_list(e->p_b);
	ft_printf("[%i]\n", e->nb_op);
}
