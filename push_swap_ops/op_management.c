/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_management.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:37:07 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/30 19:03:46 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op_name(const char *str, t_data *data)
{
	if (!data->check_bonus)
		ft_printf("%s\n", str);
}

int	push(t_stack *stack_dst, t_stack *stack_src)
{
	t_node	*temp;

	if (!stack_dst || !stack_src || !stack_src->head || stack_dst == stack_src)
		return (0);
	temp = detach_front(stack_src);
	add_front(stack_dst, temp);
	return (1);
}

int	swap(t_stack *stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if (stack == NULL || stack->size < 2)
		return (0);
	temp1 = detach_front(stack);
	temp2 = detach_front(stack);
	add_front(stack, temp1);
	add_front(stack, temp2);
	return (1);
}

int	rotate(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL || stack->size < 2)
		return (0);
	temp = detach_front(stack);
	add_back(stack, temp);
	return (1);
}

int	reverse_rotate(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL || stack->size < 2)
		return (0);
	temp = detach_back(stack);
	add_front(stack, temp);
	return (1);
}
