/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:03:17 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:53:59 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Recursively prints a memory address in hexadecimal format.
 *
 * Helper function that converts an unsigned long long value to a
 * hexadecimal string and writes it to the given file descriptor.
 *
 * @param pointer Memory address to print.
 * @param fd File descriptor to write the output to.
 * @return Number of characters written.
 */
static int	ft_ricorsive_pointer(unsigned long long pointer, int fd)
{
	int		count;
	int		rest;
	char	*base;

	count = 0;
	rest = 0;
	base = "0123456789abcdef";
	if (pointer > 15)
		count += ft_ricorsive_pointer(pointer / 16, fd);
	rest = (pointer % 16);
	count += write(fd, &base[rest], 1);
	return (count);
}

/**
 * @brief Prints a pointer in hexadecimal format prefixed with "0x".
 *
 * If the pointer is NULL, prints "(nil)". Otherwise, prints the
 * address in hexadecimal to the specified file descriptor.
 *
 * @param pointer Pointer to print.
 * @param fd File descriptor to write the output to.
 * @return Number of characters written.
 */
int	ft_forpointer(void *pointer, int fd)
{
	int					count;
	unsigned long long	ptr;

	ptr = (unsigned long long)pointer;
	if (!ptr)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(fd, "0x", 2);
	count += ft_ricorsive_pointer(ptr, fd);
	return (count);
}
