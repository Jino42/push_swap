/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/22 22:57:26 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
				do_op(e, i);
				i = 42;
			}
			i++;
		}
		if (i != 43)
			return (ft_error("Error\n"));
		print_pile(e);
		ft_strdel(&buff);
	}
	return (1);
}
