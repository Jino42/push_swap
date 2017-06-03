/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:55:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/03 20:28:00 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		make_space(t_env *e)
{
	int size_y;
	int	size_x;

	size_y = HEIGHT / e->nb_arg;
	size_x = WIDTH / 2 / e->nb_arg;
	e->height = (size_y * e->nb_arg) + 2;
	e->width = (size_x * e->nb_arg) + 2;
	e->width *= 2;
	ft_printf("Nb %i\nSize_x = %i\nSize_y = %i\nH%i W%i\n", e->nb_arg,size_x, size_y, e->height, e->width);
}

int			graph_main(t_env *e)
{
	make_space(e);
	e->mlx = mlx_init();
	e->img = mlxji_new_img(e->mlx, e->width, e->height);
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Push_me Aie Aie Aie ! <3");
	e->cur = -1;
	e->p_a = e->tmp;
	mlx_hook(e->win, 2, 0, &graph_key_on, e);
	mlx_key_hook(e->win, &graph_key_off, e);
	mlx_loop_hook(e->mlx, &graph_loop, e);
	mlx_loop(e->mlx);
	return (1);
}
