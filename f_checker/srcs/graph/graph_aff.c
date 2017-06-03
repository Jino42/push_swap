/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 20:44:35 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/03 20:25:30 by ntoniolo         ###   ########.fr       */
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

void	assign_color(t_env *e, t_list *lst, t_px *px)
{
	float	ratio;
	int		place;

	ratio = 360 / e->nb_arg;

	place = find_place(e, NB_1(lst));
	e->hue =  ratio * (float)place;
	e->saturation = 1;
	e->value = 60;
	mlxji_hsv_to_rgb(px, e->hue, e->saturation, e->value);
}

void	graph_p_b(t_env *e, int size_y, int size_x)
{
	t_pxtopx	to;
	t_px		px;
	t_list		*lst;
	int			i;

	lst = e->p_b;
	i = 1;
	while (lst)
	{
		assign_color(e, lst, &px);
		to.x1 = e->width / 2 + 1;
		if (!e->graph_line)
			to.x1 = (e->width / 2) + (size_x * find_place(e, NB_1(lst)));
		to.x2 = (e->width / 2) + (size_x * find_place(e, NB_1(lst))) + size_x;
		to.y1 = e->height - (size_y * i);
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

	lst = e->p_a;
	i = 1;
	while (lst)
	{
		assign_color(e, lst, &px);
		to.x1 = 0;
		if (!e->graph_line)
			to.x1 = size_x * find_place(e, NB_1(lst));
		to.x2 = size_x * find_place(e, NB_1(lst)) + size_x;
		to.y1 = e->height - (size_y * i);
		to.y2 = to.y1 + size_y;
		//ft_printf("y1 x2 : %i %i\n", to.y1, to.x2);
		graph_case(e, &to, &px);
		lst = lst->next;
		i++;
	}
}

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
	to.y2 = e->height -1 ;
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
