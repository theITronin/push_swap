/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 19:41:56 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
