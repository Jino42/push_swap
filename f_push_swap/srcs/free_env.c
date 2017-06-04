/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 16:40:14 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 18:45:08 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_env(t_env *e)
{
	int i;

	if (e->base)
		free(e->base);
	if (e->tab)
		free(e->tab);
	free_lst(e, e->p_a);
	free_lst(e, e->p_b);
	free_lst(e, e->solve);
	i = 0;
	while (i < NB_ALGO)
	{
		free_lst(e, e->final_solve[i]);
		i++;
	}
}

void		free_init_algo(t_env *e)
{
	free_lst(e, e->p_a);
	e->p_a = NULL;
	free_lst(e, e->p_b);
	e->p_b = NULL;
}

void		free_lst(t_env *e, t_list *need2free)
{
	t_list *lst;
	t_list *lst_past;

	(void)e;
	lst_past = NULL;
	lst = need2free;
	if (lst == NULL)
		return ;
	while (lst)
	{
		if (lst_past)
			free(lst_past);
		free(lst->content);
		lst_past = lst;
		lst = lst->next;
	}
	if (lst_past)
		free(lst_past);
	lst_past = NULL;
}
