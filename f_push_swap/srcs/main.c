/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:54:44 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 02:46:13 by ntoniolo         ###   ########.fr       */
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
	int		i, j;
	t_pi	tmp;
	char	**c_tmp;

	c_tmp = NULL;
	e->nb_arg = nb_arg - 1;
	i = 0;
	while (i < e->nb_arg)
	{
		ft_bzero(&tmp, sizeof(t_pi));
//		if (!ft_isnumber(argv[i + 1]))
//			return (ft_error("Enrtrez des nombres !\n"));
		c_tmp = ft_strsplit(argv[i + 1], ' ');
		j = 0;
		while (c_tmp[j])
		{
			tmp.nb = ft_atoi(c_tmp[j]);
			ft_lstinsert(&e->p_a, ft_lstnew(&tmp, sizeof(t_pi*)));
			ft_strdel(&c_tmp[j]);
			j++;
		}
		free(c_tmp);
		c_tmp = NULL;
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

	t_list	*lst_past;
	t_list	*lst;
	lst_past = NULL;
	lst = e->solve;
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
	lst = e->p_a;
	while (lst)
	{
		ft_printf("lol");
		if (lst_past)
			free(lst_past);
		//free(lst->content);
		lst_past = lst;
		lst = lst->next;
	}
	if (lst_past)
		free(lst_past);/*
	lst_past = NULL;
	lst = e->p_b;
	while (lst)
	{
		if (lst_past)
			free(lst_past);
		free(lst->content);
		lst_past = lst;
		lst = lst->next;
	}
	if (lst_past)
		free(lst_past);*/
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
