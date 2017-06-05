/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_max_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 21:19:48 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/05 23:37:12 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int		ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		sign = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	if (sign == 0)
		nb = nb * -1;
	return (nb);
}

int					ft_check_max_int(char *str)
{
	long int	nb;
	int			i;

	i = 0;
	while (str[i])
		i++;
	if (i > 13)
		return (0);
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	else
		return (1);
}
