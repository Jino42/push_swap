/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 18:45:19 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		init_struct_algo(t_env *e)
{
	t_pi	tmp;
	int		i;

	free_init_algo(e);
	i = 0;
	while (i < e->nb_arg)
	{
		ft_bzero(&tmp, sizeof(t_pi));
		tmp.nb = e->base[i];
		ft_lstinsert(&e->p_a, ft_lstnew(&tmp, sizeof(t_pi*)));
		i++;
	}
	e->nb_sort = 0;
	e->nb_op = 0;
}

static void		save_solve(t_env *e, int cur)
{
	e->final_solve[cur] = e->solve;
	e->solve = NULL;
}

int				loop_check(t_env *e)
{
	int i;

	i = 0;
	if (e->nb_arg > 10)
	{
		init_struct_algo(e);
		while (!verif_order(e))
			my_algo(e);
		save_solve(e, i);
		e->res[i] = e->nb_op;
	}
	else
	{
		while (i < NB_ALGO)
		{
			init_struct_algo(e);
			while (!verif_order(e))
				(e->tab_algo[i](e));
			save_solve(e, i);
			e->res[i] = e->nb_op;
			i++;
		}
	}
	return (1);
}
