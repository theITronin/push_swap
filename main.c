/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/22 12:10:05 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_data *data) //¿lo llamamos init data??¿¿iniciamos tmb bench e id_flag??
{
	t_stack *a;
	t_stack	*b;

	data->a = NULL; 
	data->b = NULL;
	data->a = (t_stack *)malloc(sizeof(t_stack));
	if (!data->a)
		print_error(-1, data);
	data->b = (t_stack *)malloc(sizeof(t_stack));
	if (!data->b)
		print_error(-1, data);
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
	data->check_bench = 0; // patch_params usa check_bench sin inicializar ¿lo metemos aqui o en main?
	data->disorder = 0.0;
	data->id_flag = INVALID_FLAG;
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
	parse_params(argc, argv, data);
	print_stack(data->a);
	return (0);
}

// void	init_stacks(t_data *data)
// {
// 	t_stack *a;
// 	t_stack	*b;

// 	a = (t_stack *)malloc(sizeof(t_stack));
// 	if (!a)
// 		print_error(-1, data);
// 	b = (t_stack *)malloc(sizeof(t_stack));
// 	if (!b)
// 		print_error(-1, data);
// 	a->head = NULL;
// 	a->tail = NULL;
// 	a->size = 0;
// 	b->head = NULL;
// 	b->tail = NULL;
// 	b->size = 0;
// 	data->a = a; 
// 	data->b = b;
// 	data->check_bench = 0;
// 	data->disorder = 0.0;
// 	data->id_flag = INVALID_FLAG;
// }
