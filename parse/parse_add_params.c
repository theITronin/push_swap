/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 18:40:59 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 18:41:08 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_params(char **numbers, t_data *data, int error)
{
	int		i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	if (error)
		print_error (-4, data);
}

void	add_nodes(char **numbers, t_data *data)
{
	int		i;
	long	n;
	t_node	*tmp;

	i = 0;
	while (numbers[i])
	{
		n = ft_atol(numbers[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_params(numbers, data, 1);
		tmp = create_node(n);
		if (!tmp)
			free_params(numbers, data, 1);
		if (check_number(data->a, n))
		{
			free(tmp);
			free_params(numbers, data, 1);
		}
		add_back(data->a, tmp);
		i++;
	}
}

void	split_params(char *raw_num, t_data *data)
{
	char	**numbers;

	numbers = ft_split(raw_num, ' ');
	if (!numbers)
		print_error(-3, data);
	else if (!numbers[0])
		free_params(numbers, data, 1);
	add_nodes(numbers, data);
	free_params(numbers, data, 0);
}
