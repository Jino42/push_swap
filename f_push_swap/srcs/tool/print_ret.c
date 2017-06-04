/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 21:29:42 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 22:46:13 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(t_env *e, t_list *l)
{
	while (l)
	{
		ft_printf("%s\n", e->op[*((int*)(l->content))]);
		l = l->next;
	}
}

void		print_ret(t_env *e)
{
	if (e->res[0] <= e->res[1] && e->res[0] <= e->res[2])
		print(e, e->final_solve[0]);
	else if (e->res[1] <= e->res[0] && e->res[1] <= e->res[2])
		print(e, e->final_solve[1]);
	else
		print(e, e->final_solve[2]);
}
