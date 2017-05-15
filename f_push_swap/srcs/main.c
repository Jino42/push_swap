/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:54:44 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/16 00:00:18 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verif_doublon(t_env *e)
{
	t_list	*i;
	t_list	*j;

	i = e->p_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*(int*)(i->content) == *(int*)(j->content))
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

static int	init_env(t_env *e, int nb_arg, char **argv)
{
	int		i;
	int		tmp;

	e->nb_arg = nb_arg - 1;
	i = 0;
	while (i < e->nb_arg)
	{
		if (!ft_isnumber(argv[i + 1]))
			return (ft_error("Enrtrez des nombres !\n"));
		tmp = ft_atoi(argv[i + 1]);
		ft_lstinsert(&e->p_a, ft_lstnew(&tmp, sizeof(int)));
		i++;
	}
	ft_printf("Pile a : ");
	print_list(e->p_a);
	ft_printf("Pile b : ");
	print_list(e->p_b);
	ft_printf("Nb_nb : %i\n", e->nb_arg);
	e->nb_a = e->nb_arg;
	if (!verif_doublon(e))
		return (ft_error("Doublon.\n"));
	crea_var(e);
	return (1);
}

static void free_env(t_env *e)
{
	free(e->p_a);
	free(e->p_b);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 1)
		return (ft_error("Error\n"));
	ft_bzero(&e, sizeof(t_env));
	if (!(init_env(&e, argc, argv)))
		return (0);
	if (loop_check(&e))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_env(&e);
	return (0);
}
