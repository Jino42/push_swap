/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:55:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/22 20:06:16 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			graph_main(t_env *e)
{
	e->mlx = mlx_init();
	e->img = mlxji_new_img(e->mlx, WIDTH, HEIGHT);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Push_me Aie Aie Aie ! <3");
	mlx_hook(e->win, 2, 0, &graph_key_on, e);
	mlx_key_hook(e->win, &graph_key_off, e);
	mlx_loop_hook(e->mlx, &graph_loop, e);
	mlx_loop(e->mlx);
	return (1);
}
