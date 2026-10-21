/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:57 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/21 16:43:14 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef enum e_flags
{
	INVALID_FLAG = -1,
	SIMPLE,
	MEDIUM, 
	COMPLEX, 
	ADAPTIVE
}	t_flags;


typedef struct	s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct	s_data
{
	t_stack		*a;
	t_stack		*b;
	t_flags		id_flag;
	int			check_bench;
	double		disorder;
}	t_data;

t_node	*create_node(int value);
t_node	*detach_front(t_stack *stack);
t_node	*detach_back(t_stack *stack);

void	clear_stack(t_stack *stack);
void	add_front(t_stack *stack, t_node *new);
void	add_back(t_stack *stack, t_node *new);
void	print_stack(t_stack *stack);
void	print_stack_reverse(t_stack *stack);
void	init_stacks(t_data *data);
void	patch_params(int argc, char **argv, t_data *data);
void	add_params(char *raw_num, t_data *data);

int		main(int argc, char **argv);
int		print_error(int	err_id, t_data *data);
int		patch_flag(char *flag, t_data *data);

#endif
