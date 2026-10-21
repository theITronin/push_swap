/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/21 17:14:00 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_data *data)
{
	t_stack *a;
	t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		print_error(-1, data);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		print_error(-1, data);
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
	data->a = a;
	data->b = b;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 1)
		return (-1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		print_error(-1, data);
	init_stacks(data);
	patch_params(argc, argv, data);
	print_stack(data->a);
	return (0);
}
