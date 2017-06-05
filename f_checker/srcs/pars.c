/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 23:10:38 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 21:34:22 by ntoniolo         ###   ########.fr       */
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

static void	pars(t_env *e, int nb_arg, char **argv)
{
	int		i;
	int		j;
	t_pi	tmp;
	char	**c_tmp;

	e->nb_arg = nb_arg - 1 - e->nb_flag;
	i = e->nb_flag;
	while (i < e->nb_arg + e->nb_flag)
	{
		c_tmp = ft_strsplit(argv[i + 1], ' ');
		j = -1;
		while (c_tmp[++j])
		{
			if (!ft_isnumber(c_tmp) || !ft_check_max_int(c_tmp[j]))
				exit(ft_error("Error\n"));
			ft_bzero(&tmp, sizeof(t_pi));
			tmp.nb = ft_atoi(c_tmp[j]);
			ft_lstinsert(&e->p_a, ft_lstnew(&tmp, sizeof(t_pi*)));
			ft_lstinsert(&e->tmp, ft_lstnew(&tmp, sizeof(t_pi*)));
			ft_strdel(&c_tmp[j]);
			e->nb_a++;
		}
		free(c_tmp);
		i++;
	}
}

int			init_env(t_env *e, int nb_arg, char **argv)
{
	pars(e, nb_arg, argv);
	if (!verif_doublon(e))
		return (ft_error("Error\n"));
	crea_var(e);
	e->nb_arg = e->nb_a;
	return (1);
}
