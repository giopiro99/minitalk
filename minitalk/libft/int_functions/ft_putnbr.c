/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:41:12 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:55:07 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Writes an integer to the standard output (stdout).
 *
 * Handles negative numbers, including the minimum integer value,
 * and writes the number as a string to stdout.
 *
 * @param n The integer to write.
 * @return The number of characters written.
 */
int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i = 1;
	}
	if (n <= 2147483647)
	{
		if (n >= 10)
		{
			i += ft_putnbr(n / 10);
		}
		n = (n % 10) + 48;
		i += write(1, &n, 1);
	}
	return (i);
}
