/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:51:15 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 01:24:42 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_op(t_env *e, int op, char verbose)
{
	e->exec[op](e);
	if (verbose)
		ft_printf("%s\n", e->op[op]);
	ft_lstinsert(&e->solve, ft_lstnew(&op, sizeof(int*)));
	e->nb_op++;
}
