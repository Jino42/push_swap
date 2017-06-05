/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 19:43:03 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	del_error(char *buff)
{
	ft_strdel(&buff);
	return (ft_error("Error\n"));
}

int			loop_check(t_env *e)
{
	char	*buff;
	int		i;

	while (!verif_order(e))
	{
		get_next_line(0, &buff);
		if (!ft_strcmp(buff, ""))
			return (-1);
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
		ft_strdel(&buff);
	}
	return (1);
}
