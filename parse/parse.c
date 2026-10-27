/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 17:40:19 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/27 18:48:45 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int	err_id, t_data *data)
{
	write (2, "Error\n", 6);
	
	if (data)
	{
		if (data->a)
			clear_stack(data->a);
		if (data->b)
			clear_stack(data->b);
		free(data);
	}
	exit(err_id);
}

void	parse_flag(char *flag, t_data *data)
{
	if (!flag || !data)
		print_error(-3, data);
	if (data->id_flag == -1)
	{
		if (ft_strcmp(flag, "--simple") == 0)
			data->id_flag = SIMPLE;
		else if (ft_strcmp(flag, "--medium") == 0)
			data->id_flag = MEDIUM;
		else if (ft_strcmp(flag, "--complex") == 0)
			data->id_flag = COMPLEX;
		else if (ft_strcmp(flag, "--adaptive") == 0)
			data->id_flag = ADAPTIVE;
		if (data->id_flag >= 0)
			return ;
	}
	if (data->check_bench == 0 && ft_strcmp(flag, "--bench") == 0)
	{
		data->check_bench = 1;
		return ;
	}
	print_error(-3, data);
}

void	parse_params(int argc, char **argv, t_data *data)
{
	int i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if ((argv[i][0] == '-' && argv[i][1] == '-') || !argv[i][0])
			parse_flag(argv[i], data);
		else
		{
			while (argv[i][j] != '\0')
			{
				if ((ft_isdigit(argv[i][j])) || ((j == 0 || argv[i][j - 1] == ' ')
					&& argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])))
					j++;
				else if (argv[i][j] == ' ')
					j++;
				else
					print_error(-2, data);
			}
			split_params(argv[i], data);
		}
		i++;
	}
}

