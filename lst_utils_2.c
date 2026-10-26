/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:44:00 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/20 14:46:23 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return NULL;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL)
		return ;
	current = stack->head;
	while (current != NULL)
	{
		ft_printf("Valor: %d\n", current->value);
		current = current->next;
	}
}

int	check_number(t_stack *stack, int value)
{
	t_node	*current;

	if (stack == NULL)
		return (0);
	current = stack->head;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

t_node	*get_node_at(t_stack *stack, int index)
{
	int		number;
	t_node	*current;

	if (stack == NULL)
		return (NULL);
	current = stack->head;
	number = 0;
	while (current != NULL)
	{
		if (number == index)
			return (current);
		current = current->next;
		number++;
	}
	return (NULL);
}
