/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:39:00 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 18:57:59 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_numbers_error(int n)
{
	char	n_char;
	long	n1;
	int		len;

	len = 0;
	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		write(2, "-", 1);
		len++;
	}
	if (n1 > 9)
		len += print_numbers_error(n1 / 10);
	n_char = n1 % 10 + '0';
	write(2, &n_char, 1);
	len++;
	return (len);
}

int	print_unsigned_n_error(unsigned int n)
{
	char	n_char;
	int		len;

	len = 0;
	if (n > 9)
		len = print_numbers_error(n / 10);
	n_char = n % 10 + '0';
	write(2, &n_char, 1);
	len++;
	return (len);
}
