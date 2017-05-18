/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:36:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/18 23:35:52 by ntoniolo         ###   ########.fr       */
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

int			algo(t_env *e)
{
	static int in_a = 1;

	if (!e->nb_a)
		in_a = 0;
	if (!e->nb_b)
		in_a = 1;
	/*if (e->nb_b > 2 &&
		ft_abs((*(int*)(e->p_b->content)) - (*(int*)((ft_lstlast(e->p_b))->content))) <
		ft_abs((*(int*)(e->p_b->content)) - (*(int*)(e->p_b->next->content))))
	{
		e->exec[RB](e);
		ft_printf("%s\n", e->op[RB]);
	}
	else*/if (e->nb_b > 1 && ((t_pi*)(e->p_b->content))->nb < (((t_pi*)((ft_lstlast(e->p_b)))->content))->nb)
	{
		e->exec[RB](e);
		ft_printf("%s\n", e->op[RB]);
	}
	else if (e->nb_a && ((t_pi*)((ft_lstlast(e->p_a))->content))->nb < ((t_pi*)(e->p_a->content))->nb)
	{
		e->exec[RRA](e);
		ft_printf("%s\n", e->op[SA]);
	}
	else if (e->nb_a > 1 && ((t_pi*)(e->p_a->content))->nb > ((t_pi*)(e->p_a->next->content))->nb)
	{
		e->exec[SA](e);
		ft_printf("%s\n", e->op[SA]);
	}
	else if (e->nb_a && in_a)
	{
		e->exec[PB](e);
		ft_printf("%s\n", e->op[PB]);
	}
	else
	{
		e->exec[PA](e);
		ft_printf("%s\n", e->op[PA]);
	}
	return (1);
}

int			find_mid(t_list *l, int size)
{
	int tab[size];
	int i, j;

	i = 0;	
	while (i < size)
	{
		tab[i] = ((t_pi*)(l->content))->nb;
		i++;
		l = l->next;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				SWAP(tab[i], tab[j]);
				i = 0;
			}
			j++;
		}
		i++;
	}
	ft_printf("__[%i]__\n", tab[i/2]);
	return (tab[i / 2]);
}

int			size_grp(t_list *l)
{
	t_pi *pi;
	int save;
	int i;

	pi = l->content;
	ft_printf("[%i||]\n", (pi)->nb);
	save = (pi)->grp;
	if (save == -1)
		return (-1);
	i = 0;
	while (l)
	{
		pi = l->content;
		if ((pi)->grp != save)
			return (i);
		l = l->next;
		i++;
	}
	return (i);
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
	int pivot = find_mid(e->p_b, size);
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
	if (size == 3)
	{
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
		((t_pi*)(e->p_a->content))->grp = -1;
		e->exec[RA](e);
		ft_printf("%s\n", e->op[RA]);
		e->nb_op++;
	}
	else if (size == 1)
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
	if (size == -1)
		exit(0);
	if (size <= 2)
	{
		ft_printf("GOOOOOOOOOOO p[%i]\n", size);
		case_a(e, size);
		return (1);
	}
	int pivot = find_mid(e->p_a, size);
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
				e->exec[RRA](e);
				ft_printf("%s\n", e->op[RRA]);
				e->nb_op++;
				nb_ra--;
			}
			return (1);
		}
		(void)grp;
		ft_printf("Gr[[%i]\n", pi->grp);
		if (pi->nb > pivot)
		{
			(pi)->grp = e->cur_grp + 1;
			e->exec[RA](e);
			ft_printf("%s\n", e->op[RA]);
			nb_ra++;
		}
		else
		{
			(pi)->grp = e->cur_grp + 2;
			e->exec[PB](e);
			ft_printf("%s\n", e->op[PB]);
		}
		ft_printf("Pile A : ");
		print_list(e->p_a);
		ft_printf("Pile B : ");
		print_list(e->p_b);
		ft_printf("[%i]\n", e->nb_op);
		e->nb_op++;
	}
	while (nb_ra)
	{
		e->exec[RRA](e);
		ft_printf("%s\n", e->op[RRA]);
		e->nb_op++;
		nb_ra--;
	}
	return (1);
}

int			my_algo(t_env *e)
{
	if (!e->nb_b)
	{
		cut_p_a(e);
		//exit(0);
		//couper p_a
	}
	else
	{
		cut_p_b(e);
		//mid pb pusha
	}
	e->cur_grp += 3;
	return (1);
}

int			loop_check(t_env *e)
{
	while (!verif_order(e))
	{
		//e->nb_op++;
		my_algo(e);
		ft_printf("Pile A : ");
		print_list(e->p_a);
		ft_printf("Pile B : ");
		print_list(e->p_b);
		ft_printf("[%i]\n", e->nb_op);
	}
	return (1);
}
