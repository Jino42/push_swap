/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:51:47 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/22 23:46:00 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	crea_var_neg(t_env *e)
{
	e->exec_neg[0] = &op_sa;
	e->exec_neg[1] = &op_sb;
	e->exec_neg[2] = &op_ss;
	e->exec_neg[3] = &op_pb;
	e->exec_neg[4] = &op_pa;
	e->exec_neg[5] = &op_rra;
	e->exec_neg[6] = &op_rrb;
	e->exec_neg[7] = &op_rrr;
	e->exec_neg[8] = &op_ra;
	e->exec_neg[9] = &op_rb;
	e->exec_neg[10] = &op_rr;
}

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
	crea_var_neg(e);
}
