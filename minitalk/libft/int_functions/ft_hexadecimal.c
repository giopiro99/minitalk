/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:55 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:54:22 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Prints an unsigned integer in hexadecimal format.
 *
 * Recursively converts the given unsigned integer to a hexadecimal string
 * and writes it to the specified file descriptor. Supports lowercase ('x')
 * and uppercase ('X') output depending on the format specifier.
 *
 * @param n The unsigned integer to print.
 * @param c Format specifier, 'x' for lowercase, 'X' for uppercase.
 * @param fd File descriptor to write the output to.
 * @return The number of characters written.
 */
int	ft_hexadecimal(unsigned int n, const char c, int fd)
{
	int		count;
	int		rest;
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	count = 0;
	if (c == 'x')
	{
		if (n > 15)
			count += ft_hexadecimal(n / 16, c, fd);
		rest = (n % 16);
		count += write(fd, &lower[rest], 1);
	}
	else if (c == 'X')
	{
		if (n > 15)
			count += ft_hexadecimal(n / 16, c, fd);
		rest = (n % 16);
		count += write(fd, &upper[rest], 1);
	}
	return (count);
}
