/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/29 20:14:57 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	t_stack *a;
	t_stack	*b;
	
	data->a = NULL;
	data->b = NULL;
	a = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!a)
		print_error(-1, data);
	data->a = a;
	b = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!b)
		print_error(-1, data);
	data->b = b;
	data->id_flag = INVALID_FLAG;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 1)
		return (-1);
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!data)
		print_error(-1, data);
	init_data(data);
	parse_params(argc, argv, data);
	lst_to_int(data);
	flag_management(data);
	memory_free(data);
	return (0);
}
