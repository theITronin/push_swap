/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:45:57 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 20:34:39 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ops(t_data *data, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
		return (ra(data));
	else if (ft_strcmp(op, "rb") == 0)
		return (rb(data));
	else if (ft_strcmp(op, "rr") == 0)
		return (rr(data));
	else if (ft_strcmp(op, "pa") == 0)
		return (pa(data));
	else if (ft_strcmp(op, "pb") == 0)
		return (pb(data));
	else if (ft_strcmp(op, "sa") == 0)
		return (sa(data));
	else if (ft_strcmp(op, "sb") == 0)
		return (sb(data));
	else if (ft_strcmp(op, "ss") == 0)
		return (ss(data));
	else if (ft_strcmp(op, "rra") == 0)
		return (rra(data));
	else if (ft_strcmp(op, "rrb") == 0)
		return (rrb(data));
	else if (ft_strcmp(op, "rrr") == 0)
		return (rrr(data));
	else
	{
		free (op);
		print_error(-1, data);
	}
}

void	read_ops(t_data *data)
{
	char	*op;
	ssize_t	bytes;

	op = (char *)malloc(4 * sizeof(char));
	if (!op)
		print_error(-1, data);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(0, op, 4);
		op[bytes] = '\0';
		ft_printf("%s", op);
		check_ops(data, op);
	}
	free(op);
	
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
	//data->check_bonus = 1;
	parse_params(argc, argv, data);
	if (data->id_flag > -1 || data->check_bench == 1)
		print_error(-1, data);
	read_ops(data);
	lst_to_int(data);
	if (data->disorder == 0.0)
		ft_printf("%s", "OK");
	else
		ft_printf("%s", "KO");
	memory_free(data);
	return (0);
}
