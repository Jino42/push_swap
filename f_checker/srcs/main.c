/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:54:44 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 22:59:20 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		make_flag(t_env *e, int argc, char **argv)
{
	int i;

	i = 0;
	while (i + 1 < argc)
	{
		if (argv[i + 1][0] == '-')
		{
			if (ft_isdigit(argv[i + 1][1]))
				return (1);
			if ('v' == argv[i + 1][1] && !argv[i + 1][2])
			{
				e->flag |= FLAG_V;
				e->nb_flag++;
			}
			else if ('n' == argv[i + 1][1] && !argv[i + 1][2])
			{
				e->flag |= FLAG_N;
				e->nb_flag++;
			}
			else
				return (ft_error("Flags Problems\n"));
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		ret;

	if (argc == 1)
		return (0);
	ft_bzero(&e, sizeof(t_env));
	if (!(make_flag(&e, argc, argv)))
		return (0);
	if (argc - e.nb_flag == 1)
		return (0);
	if (!(init_env(&e, argc, argv)))
	{
		free_env(&e);
		return (0);
	}
	sort_tab(&e);
	ret = loop_check(&e);
	if (ret == 1)
		ft_printf("OK\n");
	else if (ret == -1)
		ft_printf("KO\n");
	free_env(&e);
	return (0);
}
