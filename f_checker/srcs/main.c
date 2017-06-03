/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:54:44 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/03 19:56:16 by ntoniolo         ###   ########.fr       */
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
	e->nb_arg = nb_arg - 1 - e->nb_flag;
	i = e->nb_flag;
	while (i < e->nb_arg + e->nb_flag)
	{
		c_tmp = ft_strsplit(argv[i + 1], ' ');
		if (!ft_isnumber(c_tmp))
			return (ft_error("Entrez des nombres !\n"));
		j = 0;
		while (c_tmp[j])
		{
			ft_bzero(&tmp, sizeof(t_pi));
			tmp.nb = ft_atoi(c_tmp[j]);
			ft_lstinsert(&e->p_a, ft_lstnew(&tmp, sizeof(t_pi*)));
			ft_lstinsert(&e->tmp, ft_lstnew(&tmp, sizeof(t_pi*)));
			ft_strdel(&c_tmp[j]);
			j++;
			e->nb_a++;
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
	if (!verif_doublon(e))
		return (ft_error("Doublon.\n"));
	crea_var(e);
	e->nb_arg = e->nb_a;
	return (1);
}

static void free_env(t_env *e)
{
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
		if (lst_past)
			free(lst_past);
		free(lst->content);
		lst_past = lst;
		lst = lst->next;
	}
	if (lst_past)
		free(lst_past);
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
		free(lst_past);
	free(e->tab);
}

int		make_flag(t_env *e, int argc, char **argv)
{
	int i;

	i = 0;
	while (i + 1 < argc)
	{
		if (argv[i + 1][0] == '-')
		{
			if ('v' == argv[i + 1][1])
			{
				e->flag |= FLAG_V;
				e->nb_flag++;
			}
			else if ('n' == argv[i + 1][1])
			{
				e->flag |= FLAG_N;
				e->nb_flag++;
			}
			else
				return (ft_error("Flags Problems\n"));
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 1)
		return (ft_error("Error\n"));
	ft_bzero(&e, sizeof(t_env));
	if (!(make_flag(&e, argc, argv)))
		return (0);
	if (!(init_env(&e, argc, argv)))
		return (0);
	sort_tab(&e);
	if (loop_check(&e))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	t_list *l;

	l = e.solve;
	while (l)
	{
		ft_printf("%s\n", e.op[*((int*)(l->content))]);
		l = l->next;
	}
	if (e.flag & FLAG_N)
		graph_main(&e);
	free_env(&e);
	return (0);
}
