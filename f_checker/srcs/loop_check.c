/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 23:39:57 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	del_error(char *buff)
{
	ft_strdel(&buff);
	return (ft_error("Error\n"));
}

static int	loop_op(t_env *e, char *buff)
{
	int i;

	i = 0;
	while (buff && i < NB_OP)
	{
		if (!ft_strcmp(buff, e->op[i]))
		{
			do_op(e, i);
			i = 42;
		}
		i++;
	}
	if (i != 43)
		return (del_error(buff));
	if (e->flag & FLAG_V)
		print_pile(e);
	return (1);
}

int			loop_check(t_env *e)
{
	char	*buff;

	while (1)
	{
		get_next_line(0, &buff);
		if (!ft_strcmp(buff, ""))
		{
			if (!verif_order(e))
				return (-1);
			else
				return (1);
		}
		if (!(loop_op(e, buff)))
			return (0);
		ft_strdel(&buff);
		if (verif_order(e))
			return (1);
	}
	return (1);
}
