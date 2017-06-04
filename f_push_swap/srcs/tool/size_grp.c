/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:44:26 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 01:22:20 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			size_grp(t_list *l)
{
	t_pi *pi;
	int save;
	int i;

	pi = l->content;
	save = (pi)->grp;
	if (save == -1)
		return (-1);
	i = 0;
	while (l)
	{
		pi = l->content;
		if ((pi)->grp != save)
			return (i);
		l = l->next;
		i++;
	}
	return (i);
}
