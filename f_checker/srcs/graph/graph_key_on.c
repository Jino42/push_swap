/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_key_on.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:24:16 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 23:04:30 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	graph_key_go_2(int keycode, t_env *e)
{
	if (keycode == 49 && e->one_up == 0 &&
			!e->key[69] && !e->key[78])
	{
		if (e->go == 1)
		{
			e->go = 0;
			e->cur--;
		}
		else
		{
			(e->go = 1);
			e->cur++;
		}
	}
}

static void	graph_key_go(int keycode, t_env *e)
{
	if (keycode == 69 && !e->one_up && !e->go && !e->key[49])
	{
		e->one_up = 1;
		if (e->cur < e->nb_op - 1)
			e->cur++;
		else
			e->one_up = 0;
	}
	else if (keycode == 78 && !e->one_up && !e->go && !e->key[49])
	{
		e->one_up = -1;
		if (e->cur > 0)
			e->neg = 1;
		else
			e->one_up = 0;
	}
	else
		graph_key_go_2(keycode, e);
}

int			graph_key_on(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode)
		e->key[keycode] = 1;
	graph_key_go(keycode, e);
	if (keycode == 257)
	{
		if (e->graph_line == 0)
			e->graph_line = 1;
		else
			e->graph_line = 0;
	}
	return (0);
}
