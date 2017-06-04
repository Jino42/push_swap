/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:29:14 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/04 18:43:19 by ntoniolo         ###   ########.fr       */
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
	t_pi	*tmp;
	int		tic_tac = 0;
	int		cur_grp = 7845600;

	while (l)
	{
		tmp = l->content;
		if (tmp->grp != cur_grp)
		{
			cur_grp = tmp->grp;
			tic_tac += 1;
			ft_printf("\033[0m");
			if (cur_grp == -1)
				ft_printf("\033[33m");
			else if (cur_grp == -2)
				ft_printf("\033[32m");
			else if (tic_tac & 1)
				ft_printf("\033[36m");
			else
				ft_printf("\033[35m");
		}
		ft_printf("%i ", (tmp)->nb);
		l = l->next;
	}
	ft_printf("\033[0m");
	ft_printf("\n");
}

int	ft_isnumber(char **str)
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
