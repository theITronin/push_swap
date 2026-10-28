/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 18:40:59 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/28 11:00:08 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *nptr)
{
	long	n;
	int		negative;
	size_t	i;

	n = 0;
	negative = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	if (negative == 1)
		n = n * -1;
	return (n);
}

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
	long	n;
	t_node	*tmp;

	i = 0;
	while (numbers[i])
	{
		n = ft_atol(numbers[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error (-4, data);
		tmp = create_node(n);
		if (!tmp)
			print_error(-1, data);
		if (check_number(data->a, n))
		{
			print_error(-1, data);
			free(tmp);
		}
		add_back(data->a, tmp);
		free(tmp);
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

