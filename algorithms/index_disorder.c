/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:02:51 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/25 09:36:08 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	index_disorder(int *array, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	if (size < 2)
    	return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (array[i] > array[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}
