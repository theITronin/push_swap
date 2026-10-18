/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer_disorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbv <pbv@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:02:51 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/18 19:37:51 by pbv              ###   ########.fr       */
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

int	main(void)
{
	double	disord_index;
	int		array[] = {3,2,5,6,7,3,6,1};
	
	disord_index = index_disorder(array, 8);
	printf("Índice de desorden: %.2f\n", disord_index);
	return (0);
}