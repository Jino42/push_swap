/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:55:45 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 21:14:02 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_dir(t_pi *tmp, int *cur_grp, int *tic_tac)
{
	if (tmp->grp != *cur_grp)
	{
		*cur_grp = tmp->grp;
		*tic_tac += 1;
		ft_printf("\033[0m");
		if (*cur_grp == -1)
			ft_printf("\033[33m");
		else if (*cur_grp == -2)
			ft_printf("\033[32m");
		else if (*tic_tac & 1)
			ft_printf("\033[36m");
		else
			ft_printf("\033[35m");
	}
}

static void	print_list(t_list *l)
{
	t_pi	*tmp;
	int		tic_tac;
	int		cur_grp;

	tic_tac = 0;
	cur_grp = 987654;
	while (l)
	{
		tmp = l->content;
		print_dir(tmp, &cur_grp, &tic_tac);
		ft_printf("%i ", (tmp)->nb);
		l = l->next;
	}
	ft_printf("\033[0m\n");
}

void		print_pile(t_env *e)
{
	ft_printf("OP[%i]\n", e->nb_op);
	ft_printf("Pile A : ");
	print_list(e->p_a);
	ft_printf("Pile B : ");
	print_list(e->p_b);
	ft_printf("\n");
}
