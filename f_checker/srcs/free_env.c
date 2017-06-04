/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 16:40:14 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 00:34:17 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_env(t_env *e)
{
	if (e->tab)
		free(e->tab);
	free_lst(e, e->p_a);
	free_lst(e, e->p_b);
	free_lst(e, e->solve);
	free_lst(e, e->tmp);
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
