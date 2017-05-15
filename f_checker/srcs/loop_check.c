/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/15 22:55:31 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int verif_order(t_env *e)
{
	t_list	*i;

	if (e->nb_b)
		return (0);
	i = e->p_a;
	while (i->next)
	{
		if (*(int*)(i->content) > *(int*)(i->next->content))
			return (0);
		i = i->next;
	}
	return (1);
}

int			loop_check(t_env *e)
{
	char	*buff;
	int		i;

	while (!verif_order(e))
	{
		get_next_line(0, &buff);
		i = 0;
		while (buff && i < NB_OP)
		{
			if (!ft_strcmp(buff, e->op[i]))
			{
				e->exec[i](e);
				i = 42;
			}
			i++;
		}
		if (i != 43)
			return (ft_error("Error\n"));
		ft_printf("Pile A : ");
		print_list(e->p_a);
		ft_printf("Pile B : ");
		print_list(e->p_b);
		ft_printf("\n");
		ft_strdel(&buff);
	}
	return (1);
}
