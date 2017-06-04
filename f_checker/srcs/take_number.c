/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:37:09 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 20:38:54 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			nb_1(t_list *l)
{
	return ((((t_pi*)(l->content))->nb));
}

int			nb_2(t_list *l)
{
	return ((((t_pi*)(l->next->content))->nb));
}

int			nb_3(t_list *l)
{
	return ((((t_pi*)(l->next->next->content))->nb));
}
