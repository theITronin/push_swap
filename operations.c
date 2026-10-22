/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:05:29 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/22 16:10:05 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		printf("pb\n");
}

void	sa(t_stack *a)
{
	if (swap(a))
		printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b))
		printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	result1;
	int	result2;
	
	result1 = swap(a);
	result2 = swap(b);
	if (result1 == 1 || result2 == 1)
		printf("ss\n");
}

void	ra(t_stack *a)
{
	if (rotate(a))
		printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate(b))
		printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	result1;
	int	result2;

	result1 = rotate(a);
	result2 = rotate(b);
	if (result1 == 1 || result2 == 1)
		printf("rr\n");
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	result1;
	int	result2;
	
	result1 = reverse_rotate(a);
	result2 = reverse_rotate(b);
	if (result1 == 1 || result2 == 1)
		printf("rrr\n");
}
