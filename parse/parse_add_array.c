/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:25:23 by dbustama          #+#    #+#             */
/*   Updated: 2026/11/02 11:43:00 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j + 1] < tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	find_index(int *array, t_data *data)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < data->a->size)
	{
		node = data->a->head;
		while (node)
		{
			if (array[i] == node->value)
				node->n_index = i;
			node = node->next;
		}
		i++;
	}
}

void	lst_to_int(t_data *data)
{
	t_node	*node;
	int		i;
	int		*array;

	i = 0;
	array = (int *)malloc(data->a->size * sizeof(int));
	if (!array)
		print_error(-7, data);
	while (i < data->a->size)
	{
		node = get_node_at(data->a, i);
		array[i] = node->value;
		i++;
	}
	data->disorder = index_disorder(array, data->a->size);
	ft_sort_int_tab(array, data->a->size);
	find_index(array, data);
	free (array);
}
