/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 20:44:35 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/22 22:23:01 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_place(t_env *e, int nb)
{
	int	i;

	i = 0;
	while (i < e->nb_arg)
	{
		if (e->tab[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

void	graph_p_b(t_env *e, int size_y, int size_x)
{
	t_pxtopx	to;
	t_px		px;
	t_list		*lst;
	int			i;

	px.r = 110;
	px.b = 10;
	px.g = 62;
	lst = e->p_b;
	i = 1;
	while (lst)
	{
		to.x1 = (WIDTH / 2) + (size_x * find_place(e, NB_1(lst)));
		to.x2 = to.x1 + size_x;
		to.y1 = HEIGHT - (size_y * i);
		to.y2 = to.y1 + size_y;
		graph_case(e, &to, &px);
		lst = lst->next;
		i++;
	}
}

void	graph_p_a(t_env *e, int size_y, int size_x)
{
	t_pxtopx	to;
	t_px		px;
	t_list		*lst;
	int			i;

	px.r = 110;
	px.b = 10;
	px.g = 62;
	lst = e->p_a;
	i = 1;

	while (lst)
	{
		to.x1 = size_x * find_place(e, NB_1(lst));
		to.x2 = to.x1 + size_x;
		to.y1 = HEIGHT - (size_y * i);
		to.y2 = to.y1 + size_y;
		//ft_printf("X : %i %i\nY : %i %i\n\n", to.x1, to.x2, to.y1, to.y2);
		graph_case(e, &to, &px);
		lst = lst->next;
		i++;
	}
}

void	graph_value(t_env *e)
{
	int			size_y;
	int			size_x;

	size_y = HEIGHT / e->nb_arg;
	size_x = WIDTH / 2 / e->nb_arg;
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
	to.x1 = WIDTH / 2;
	to.x2 = WIDTH / 2;
	to.y2 = HEIGHT -1 ;
	mlxji_draw_line(e->img, &px, &to);
}

int		graph_aff(t_env *e)
{
	static int i = 0;
	i++;
	mlxji_clear_img(e->img);
	usleep(10000);
	print_middle(e);
	graph_value(e);
	t_px px;
	px.r = 250;
	px.g = 50;
	px.b = 0;
	mlxji_put_pixel(e->img, i, i, &px);
	mlxji_put_pixel(e->img, i+1, i, &px);
	mlxji_put_pixel(e->img, i, i+1, &px);
	mlxji_put_pixel(e->img, i+1, i+1, &px);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (1);
}
