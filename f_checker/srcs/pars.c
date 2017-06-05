/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 23:10:38 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 23:32:31 by ntoniolo         ###   ########.fr       */
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

static int	loop_tab(t_env *e, char **c_tmp)
{
	t_pi	tmp;
	int		j;

	j = -1;
	while (c_tmp[++j])
	{
		if (!ft_isnumber(c_tmp) || !ft_check_max_int(c_tmp[j]))
		{
			ft_strdel(&c_tmp[j]);
			while (c_tmp[++j])
				ft_strdel(&c_tmp[j]);
			free(c_tmp);
			return (ft_error("Error\n"));
		}
		ft_bzero(&tmp, sizeof(t_pi));
		tmp.nb = ft_atoi(c_tmp[j]);
		ft_lstinsert(&e->p_a, ft_lstnew(&tmp, sizeof(t_pi*)));
		ft_lstinsert(&e->tmp, ft_lstnew(&tmp, sizeof(t_pi*)));
		ft_strdel(&c_tmp[j]);
		e->nb_a++;
	}
	return (1);
}

static int	pars(t_env *e, int nb_arg, char **argv)
{
	int		i;
	char	**c_tmp;

	e->nb_arg = nb_arg - 1 - e->nb_flag;
	i = e->nb_flag;
	c_tmp = NULL;
	while (i < e->nb_arg + e->nb_flag)
	{
		c_tmp = ft_strsplit(argv[i + 1], ' ');
		if (!c_tmp[0])
		{
			free(c_tmp);
			return (ft_error("Error\n"));
		}
		if (!(loop_tab(e, c_tmp)))
			return (0);
		free(c_tmp);
		i++;
	}
	return (1);
}

int			init_env(t_env *e, int nb_arg, char **argv)
{
	if (!(pars(e, nb_arg, argv)))
		return (0);
	if (!verif_doublon(e))
		return (ft_error("Error\n"));
	crea_var(e);
	e->nb_arg = e->nb_a;
	return (1);
}
