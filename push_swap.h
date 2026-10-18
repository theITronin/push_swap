/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:57 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/18 11:07:34 by dbustama         ###   ########.fr       */
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

typedef struct s_stack
{
	int					n;
	struct stack_list	*next;
	struct stack_list	*prev;
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


#endif
