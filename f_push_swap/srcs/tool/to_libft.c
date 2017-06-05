/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:29:14 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 19:44:59 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(int *tab, int size)
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

int		ft_isnumber(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((!ft_isdigit(str[i][j]) && str[i][j] != '-') ||
				(str[i][j] == '-' && str[i][j + 1] == '\0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

void	del_lst_pile(void *ptr, size_t size)
{
	(void)size;
	free(ptr);
	ptr = NULL;
}
