/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:05:29 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/22 16:40:49 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		ft_printf("pb\n");
}

void	sa(t_stack *a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	result1;
	int	result2;
	
	result1 = swap(a);
	result2 = swap(b);
	if (result1 == 1 || result2 == 1)
		ft_printf("ss\n");
}

void	ra(t_stack *a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	result1;
	int	result2;

	result1 = rotate(a);
	result2 = rotate(b);
	if (result1 == 1 || result2 == 1)
		ft_printf("rr\n");
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	result1;
	int	result2;
	
	result1 = reverse_rotate(a);
	result2 = reverse_rotate(b);
	if (result1 == 1 || result2 == 1)
		ft_printf("rrr\n");
}
