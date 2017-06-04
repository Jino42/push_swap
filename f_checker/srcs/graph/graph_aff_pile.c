/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_aff_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 23:30:28 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 23:37:05 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_place(t_env *e, int nb)
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

static void	assign_color(t_env *e, t_list *lst, t_px *px)
{
	float	ratio;
	int		place;

	ratio = 360 / e->nb_arg;
	place = find_place(e, nb_1(lst));
	e->hue = ratio * (float)place;
	e->saturation = 1;
	e->value = 60;
	mlxji_hsv_to_rgb(px, e->hue, e->saturation, e->value);
}

void		graph_p_b(t_env *e, int size_y, int size_x)
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
			to.x1 = (e->width / 2) + (size_x * find_place(e, nb_1(lst)));
		to.x2 = (e->width / 2) + (size_x * find_place(e, nb_1(lst))) + size_x;
		to.y1 = e->height - (size_y * i);
		to.y2 = to.y1 + size_y;
		graph_case(e, &to, &px);
		lst = lst->next;
		i++;
	}
}

void		graph_p_a(t_env *e, int size_y, int size_x)
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
			to.x1 = size_x * find_place(e, nb_1(lst));
		to.x2 = size_x * find_place(e, nb_1(lst)) + size_x;
		to.y1 = e->height - (size_y * i);
		to.y2 = to.y1 + size_y;
		graph_case(e, &to, &px);
		lst = lst->next;
		i++;
	}
}
