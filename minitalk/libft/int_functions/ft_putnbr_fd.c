/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:41:12 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:54:46 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Writes an integer to a given file descriptor.
 *
 * Handles negative numbers, including the minimum integer value,
 * and writes the number as a string to the specified file descriptor.
 *
 * @param n The integer to write.
 * @param fd The file descriptor where the output is written.
 * @return The number of characters written.
 */
int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n <= 2147483647)
	{
		if (n >= 10)
		{
			count += ft_putnbr_fd(n / 10, fd);
		}
		n = (n % 10) + 48;
		count += write(fd, &n, 1);
	}
	return (count);
}
