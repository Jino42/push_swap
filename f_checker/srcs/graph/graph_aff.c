/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 20:44:35 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 23:34:41 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	graph_value(t_env *e)
{
	int			size_y;
	int			size_x;

	size_y = e->height / e->nb_arg;
	size_x = e->width / 2 / e->nb_arg;
	graph_p_a(e, size_y, size_x);
	graph_p_b(e, size_y, size_x);
}

void	print_middle(t_env *e)
{
	t_pxtopx	to;
	t_px		px;

	ft_bzero(&to, sizeof(t_pxtopx));
	ft_bzero(&px, sizeof(t_px));
	px.r = 50;
	px.b = 10;
	px.g = 150;
	to.x1 = e->width / 2;
	to.x2 = e->width / 2;
	to.y2 = e->height - 1;
	mlxji_draw_line(e->img, &px, &to);
}

int		graph_aff(t_env *e)
{
	mlxji_clear_img(e->img);
	print_middle(e);
	graph_value(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (1);
}
