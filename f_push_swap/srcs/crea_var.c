/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:51:47 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/15 23:59:12 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		crea_var(t_env *e)
{
	strcpy(e->op[0], "sa");
	e->exec[0] = &op_sa;
	strcpy(e->op[1], "sb");
	e->exec[1] = &op_sb;
	strcpy(e->op[2], "ss");
	e->exec[2] = &op_ss;
	strcpy(e->op[3], "pa");
	e->exec[3] = &op_pa;
	strcpy(e->op[4], "pb");
	e->exec[4] = &op_pb;
	strcpy(e->op[5], "ra");
	e->exec[5] = &op_ra;
	strcpy(e->op[6], "rb");
	e->exec[6] = &op_rb;
	strcpy(e->op[7], "rr");
	e->exec[7] = &op_rr;
	strcpy(e->op[8], "rra");
	e->exec[8] = &op_rra;
	strcpy(e->op[9], "rrb");
	e->exec[9] = &op_rrb;
	strcpy(e->op[10], "rrr");
	e->exec[10] = &op_rrr;
}
