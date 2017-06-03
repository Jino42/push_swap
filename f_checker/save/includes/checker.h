/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:55:54 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/15 22:06:04 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/ft_printf.h"

# define NB_OP 11

#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

typedef struct		s_env
{
	int			nb_arg;
	int			nb_a;
	t_list			*p_a;
	int			nb_b;
	t_list			*p_b;
	char		op[NB_OP][4];
	int			(*exec[NB_OP])(struct s_env *e);
}					t_env;

void print_tab(int *tab, int size);
void print_list(t_list *l);
int	ft_isnumber(char *str);
int ft_error(char *str);
t_list		*ft_lstlast(t_list *l);
void	ft_remove_index_lst(t_list **l, size_t size, void (*f)(void *, size_t));

void	del_lst_pile(void *ptr, size_t size);

int	loop_check(t_env *e);

void        crea_var(t_env *e);


int			op_sa(t_env *e);
int			op_sb(t_env *e);
int			op_ss(t_env *e);
int			op_pb(t_env *e);
int			op_pa(t_env *e);
int			op_ra(t_env *e);
int			op_rb(t_env *e);
int			op_rr(t_env *e);
int			op_rra(t_env *e);
int			op_rrb(t_env *e);
int			op_rrr(t_env *e);


#endif
