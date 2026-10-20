/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:35:15 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/20 18:39:20 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_stack *stack, t_node *new)
{
	if (stack == NULL || new == NULL)
		return ;
	if (stack->head == NULL)
	{
		stack->head = new;
		new->next = NULL;
		new->prev = NULL;
		stack->tail = new;
	}
	else
	{
		new->next = stack->head;
		stack->head->prev = new;
		new->prev = NULL;
		stack->head = new;
	}
	stack->size += 1;
}

void	add_back(t_stack *stack, t_node *new)
{
	if (stack == NULL || new == NULL)
		return ;
	if (stack->tail == NULL)
	{
		stack->tail = new;
		stack->head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->prev = stack->tail;
		stack->tail->next = new;
		new->next = NULL;
		stack->tail = new;
	}
	stack->size += 1;
}

t_node	*detach_front(t_stack *stack)
{
	t_node	*temporary;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	temporary = stack->head;
	stack->head = stack->head->next;
	if (stack->head != NULL)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	temporary->next = NULL;
	temporary->prev = NULL;
	stack->size -= 1;
	return (temporary);
}

t_node	*detach_back(t_stack *stack)
{
	t_node	*temporary;

	if (stack == NULL || stack->tail == NULL)
		return (NULL);
	temporary = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->tail != NULL)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	temporary->prev = NULL;
	stack->size -= 1;
	return (temporary);
}

void	clear_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL)
		return ;
	while (stack->head != NULL)
	{
		current = detach_front(stack);
		free(current);
	}
}