/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 21:16:47 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/23 01:03:00 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	graph_case(t_env *e, t_pxtopx *to, t_px *px)
{
	int			save_x1;

	save_x1 = to->x1;
	while (to->y1 < to->y2)
	{
		to->x1 = save_x1;
		while (to->x1 < to->x2)
		{
			mlxji_put_pixel(e->img, to->x1, to->y1, px);
			to->x1++;
		}
		to->y1++;
	}
}
