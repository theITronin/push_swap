/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 18:38:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 18:57:13 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putlong_base_error(unsigned long nbr, char *base)
{
	unsigned long		counter;
	int					len;

	len = 0;
	counter = 0;
	while (base[counter] != '\0')
		counter++;
	if (nbr >= counter)
		len += ft_putlong_base_error(nbr / counter, base);
	write(2, &base[nbr % counter], 1);
	len++;
	return (len);
}

int	print_long_hexadecimal_error(unsigned long n, char c)
{
	if (c == 'x')
		return (ft_putlong_base_error(n, "0123456789abcdef"));
	if (c == 'X')
		return (ft_putlong_base_error(n, "0123456789ABCDEF"));
	return (0);
}

int	print_pointer_error(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (print_string_error("(nil)"));
	len = print_string_error("0x");
	len += print_long_hexadecimal_error(n, 'x');
	return (len);
}
