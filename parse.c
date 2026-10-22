/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 17:40:19 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/22 12:10:54 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int	err_id, t_data *data)
{
	write (2, "Error\n", 6);
	
	if (data)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		free(data);
	}
	exit(err_id);
}

int	parse_flag(char *flag, t_data *data)
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
			return (1);
	}
	if (data->check_bench == 0 && ft_strcmp(flag, "--bench") == 0)
		return (data->check_bench = 1);
	return (print_error(-3, data));
};

void	parse_params(int argc, char **argv, t_data *data)
{
	int i;
	int	j;

	i = 1;
	data->id_flag = INVALID_FLAG;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' && argv[i][1] == '-')
			parse_flag(argv[i], data);
		else
		{
			while (argv[i][j] != '\0')
			{
				if ((ft_isdigit(argv[i][j])) || (argv[i][0] == '-' && ft_isdigit(argv[i][j + 1])))
					j++;
				else if (argv[i][j] == ' ')
					j++;
				else
					print_error(-2, data);
			}
			add_params(argv[i], data);
		}
		i++;
	}
}

void	add_params(char *raw_num, t_data *data)
{
	int		i;
	char	**numbers;

	i = 0;
	numbers = ft_split(raw_num, ' ');
	while (numbers[i])
	{
		t_node	*tmp;
		tmp = create_node(ft_atoi(numbers[i]));
		if (!tmp)
			print_error(-1, data);
		add_back(data->a, tmp);
		i++;
	}

}
