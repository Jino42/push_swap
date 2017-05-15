/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:29:14 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/16 00:00:58 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab (int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%i ", tab[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_list(t_list *l)
{
	int		*tmp;

	while (l)
	{
		tmp = l->content;
		ft_printf("%i ", *tmp);
		l = l->next;
	}
	ft_printf("\n");
}

int	ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_error(char *str)
{
	ft_printf("%s", str);
	return (0);
}

void	del_lst_pile(void *ptr, size_t size)
{
	(void)size;
	free(ptr);
	ptr = NULL;
}
