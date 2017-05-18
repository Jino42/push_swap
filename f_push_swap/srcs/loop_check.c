/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/19 00:16:05 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int verif_order(t_env *e)
{
	t_list	*i;

	if (e->nb_b)
		return (0);
	i = e->p_a;
	while (i->next)
	{
		if (((t_pi*)(i->content))->nb > ((t_pi*)(i->next->content))->nb)
			return (0);
		i = i->next;
	}
	return (1);
}

int			case_b(t_env *e, int size)
{
	if (size == 1)
	{
		((t_pi*)(e->p_b->content))->grp = -1;
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
	}
	else
	{
		if (((t_pi*)(e->p_b->content))->nb > ((t_pi*)(e->p_b->next->content))->nb)
		{
			e->exec[SB](e);
			ft_printf("%s\n", e->op[SB]);
			e->nb_op++;
		}
		((t_pi*)(e->p_b->content))->grp = -1;
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
		((t_pi*)(e->p_b->content))->grp = -1;
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
	}
	return (1);
}

int			cut_p_b(t_env *e)
{
	t_pi *pi;
	t_list *l;
	int	size;

	size = size_grp(e->p_b);
	if (size <= 2)
	{
		case_b(e, size);
		return (1);
	}
	int pivot = find_mediane(e->p_b, size);
	l = e->p_b;
	pi = l->content;
	int grp = pi->grp;
	while (1)
	{
		l = e->p_b;
		pi = l->content;
		if ((pi)->grp != grp)
			return (1);
		(void)grp;
		ft_printf("Gr[[%i]\n", pi->grp);
		if (pi->nb > pivot)
		{
			(pi)->grp = e->cur_grp + 1;
			e->exec[PA](e);
			ft_printf("%s\n", e->op[PA]);
		}
		else
		{
			(pi)->grp = e->cur_grp + 2;
			e->exec[RB](e);
			ft_printf("%s\n", e->op[RB]);
		}
		ft_printf("Pile A : ");
		print_list(e->p_a);
		ft_printf("Pile B : ");
		print_list(e->p_b);
		ft_printf("[%i]\n", e->nb_op);
		e->nb_op++;
	}
	return (1);
}

int			case_a(t_env *e, int size)
{
	if (size == 1)
	{
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[PA]);
		e->nb_op++;
	}
	else
	{
		if (((t_pi*)(e->p_a->content))->nb > ((t_pi*)(e->p_a->next->content))->nb)
		{
			e->exec[SA](e);
			ft_printf("%s\n", e->op[SA]);
			e->nb_op++;
		}
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		e->nb_op++;
	}
	return (1);
}

int			cut_p_a(t_env *e)
{
	t_pi *pi;
	t_list *l;
	int size;
	int	nb_ra = 0;


	size = size_grp(e->p_a);
	if (size <= 2)
	{
		case_a(e, size);
		return (1);
	}
	int pivot = find_mediane(e->p_a, size);
	l = e->p_a;
	pi = l->content;
	int grp = pi->grp;
	while (1)
	{
		l = e->p_a;
		pi = l->content;
		if ((pi)->grp != grp)
		{
			while (nb_ra)
			{
				do_op(e, RRA, VERB);
				nb_ra--;
			}
			return (1);
		}
		if (pi->nb > pivot)
		{
			(pi)->grp = e->cur_grp + 1;
			do_op(e, RA, VERB);
			nb_ra++;
		}
		else
		{
			(pi)->grp = e->cur_grp + 2;
			do_op(e, PB, VERB);
		}
		print_pile(e);
	}
	return (1);
}

int			my_algo(t_env *e)
{
	if (!e->nb_b)
		cut_p_a(e);
	else
		cut_p_b(e);
	e->cur_grp += 3;
	return (1);
}

int			loop_check(t_env *e)
{
	while (!verif_order(e))
	{
		my_algo(e);
		ft_printf("Pile A : ");
		print_list(e->p_a);
		ft_printf("Pile B : ");
		print_list(e->p_b);
		ft_printf("[%i]\n", e->nb_op);
	}
	return (1);
}
