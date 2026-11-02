/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:44:16 by dbustama          #+#    #+#             */
/*   Updated: 2026/11/02 11:44:22 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef enum e_flags
{
	INVALID_FLAG = -1,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_flags;

typedef struct s_node
{
	int				value;
	int				n_index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_flags		id_flag;
	int			check_bench;
	int			check_bonus;
	double		disorder;
	int			ops_counter[11];
}	t_data;

t_node	*create_node(int value);
t_node	*detach_front(t_stack *stack);
t_node	*detach_back(t_stack *stack);
t_node	*get_node_at(t_stack *stack, int index);

void	clear_stack(t_stack *stack);
void	add_front(t_stack *stack, t_node *new);
void	add_back(t_stack *stack, t_node *new);
void	print_stack(t_stack *stack);
void	init_data(t_data *data);
void	parse_params(int argc, char **argv, t_data *data);
void	add_parse_params(char *raw_num, t_data *data);
void	free_params(char **numbers, t_data *data, int error);
void	add_nodes(char **numbers, t_data *data);
void	split_params(char *raw_num, t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	alg_simple(t_data *data);
void	alg_medium(t_data *data);
void	alg_complex(t_data *data);
void	alg_adaptive(t_data *data);
void	bench(t_data *data);
void	flag_management(t_data *data);
void	memory_free(t_data *data);
void	ft_sort_int_tab(int *tab, int size);
void	print_error(int err_id, t_data *data);
void	parse_flag(char *flag, t_data *data);
void	lst_to_int(t_data *data);
void	sort_b(t_data *data);
void	print_op_name(const char *str, t_data *data);
void	check_ops(t_data *data, char *op);
void	read_ops(t_data *data);
void	print_disorder(t_data *data);
void	sort_five_or_less(t_data *data);
void	sort_three_or_less(t_data *data);

int		main(int argc, char **argv);
int		check_number(t_stack *stack, int value);
int		push(t_stack *stack_dst, t_stack *stack_src);
int		swap(t_stack *stack);
int		rotate(t_stack *stack);
int		reverse_rotate(t_stack *stack);
int		find_min_node(t_data *data);
int		ft_sqrt(int nb);
int		find_max_node(t_data *data);
int		get_max_bits(int size);

long	ft_atol(char *nptr);

double	index_disorder(int *array, int size);

char	*print_o_adaptive(t_data *data);

#endif
