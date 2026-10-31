/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:41:31 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/31 18:41:53 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
