/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 18:40:59 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 18:47:53 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_params(char **numbers)
{
	int		i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	add_nodes(char **numbers, t_data *data)
{
	int		i;
	int		n;
	t_node	*tmp;

	i = 0;
	while (numbers[i])
	{
		n = ft_atoi(numbers[i]);
		tmp = create_node(n);
		if (!tmp)
			print_error(-1, data);
		if (check_number(data->a, n))
			print_error(-1, data);
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
	{
		free (numbers);
		print_error(-3, data);
	}
	add_nodes(numbers, data);
	free_params(numbers);
}

