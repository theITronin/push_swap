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
	t_node	*p;

	if (stack == NULL)
		return ;
	p = stack->head;
	while (p != NULL)
	{
		printf("Valor: %d\n", p->value);
		p = p->next;
	}
}

void	print_stack_reverse(t_stack *stack)
{
	t_node	*p;

	if (!stack)
		return ;
	p = stack->tail;
	while (p != NULL)
	{
		printf("Valor: %d\n", p->value);
		p = p->prev;
	}
}
