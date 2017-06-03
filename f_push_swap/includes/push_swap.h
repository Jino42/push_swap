/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:55:54 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/05/22 21:18:51 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define WIDTH 1000
# define HEIGHT 1000

# include "../../libft/includes/ft_printf.h"
# include "../../libmlxji/includes/mlxji.h"
# include <mlx.h>

# define NB_1(lst) (((t_pi*)(lst->content))->nb)
# define NB_2(lst) (((t_pi*)(lst->next->content))->nb)
# define NB_3(lst) (((t_pi*)(lst->next->next->content))->nb)

# define OP_1(lst) (*(int*)(lst->content))
# define OP_2(lst) (*(int*)(lst->next->content))

# define FLAG_V (1 << 1)
# define FLAG_N (1 << 2)
# define SORTED (1 << 3)

# define NB_OP 11
# define SA 0 
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

typedef struct		s_pi
{
	int				nb;
	int				grp;
}					t_pi;

typedef struct		s_env
{
	int			nb_sort;
	int			nb_arg;
	int			nb_op;
	int			cur_grp;
	int			nb_a;
	t_list			*p_a;
	int			nb_b;
	t_list			*p_b;
	char		op[NB_OP][4];
	int			(*exec[NB_OP])(struct s_env *e);
	t_list		*solve;
	t_list		*final_solve;
	int			*tab;
	char		flag;
	char		nb_flag;

	void		*mlx;
	void		*win;
	t_img		*img;
	int			key[269];
}					t_env;

void 	print_tab(int *tab, int size);
void 	print_list(t_list *l);
int		ft_isnumber(char **str);
int		ft_error(char *str);
t_list	*ft_lstlast(t_list *l);
void	ft_remove_index_lst(t_list **l, size_t size, void (*f)(void *, size_t));

int		sort_tab(t_env *e);
int		size_grp(t_list *l);
void	print_pile(t_env *e);
void	del_lst_pile(void *ptr, size_t size);
int		join_op(t_env *e);

int		loop_check(t_env *e);
int		find_mediane(t_list *l, int size);
void	do_op(t_env *e, int op, char flag);

void        crea_var(t_env *e);
int			verif_order(t_env *e);

int			my_algo(t_env *e);

int			algo_p_a(t_env *e);
int			case_a(t_env *e, int size);

int			algo_p_b(t_env *e);
int			case_b(t_env *e, int size);

int			graph_loop(t_env *e);
int			graph_main(t_env *e);
int			graph_key_on(int keycode, t_env *e);
int			graph_key_off(int keycode, t_env *e);
int			graph_aff(t_env *e);
void		graph_case(t_env *e, t_pxtopx *to, t_px *px);

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
