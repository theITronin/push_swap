/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:57 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/20 14:45:24 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

enum all_flags
{
	INVALID_FLAG = -1,
	SIMPLE,
	MEDIUM, 
	COMPLEX, 
	ADAPTIVE
};

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

typedef struct s_list
{
	struct s_stack	a;
	struct s_stack	b;
	int				len_a;
	int				len_b;
	int				check_flag;
	int				check_bench;
	enum all_flags	id_flag;
}	t_list;

t_node	*create_node(int value);
t_node	*detach_front(t_stack *stack);
t_node	*detach_back(t_stack *stack);

void	clear_stack(t_stack *stack);
void	add_front(t_stack *stack, t_node *new);
void	add_back(t_stack *stack, t_node *new);
void	print_stack(t_stack *stack);
void	print_stack_reverse(t_stack *stack);

#endif
