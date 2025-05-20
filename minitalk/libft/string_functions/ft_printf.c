/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:19:57 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:11:28 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Processes a single format specifier and prints the corresponding argument.
 *
 * Checks the format specifier pointed by 'format' and uses the variable
 * argument list 'args' to retrieve and print the corresponding value
 * to the file descriptor 'fd'. Supports specifiers: %, c, p, s, d, i, u, x, X.
 *
 * @param format Pointer to the format specifier character.
 * @param args The variable argument list.
 * @param fd The file descriptor to print to.
 * @return int The number of characters printed.
 */
static int	check_format(const char *format, va_list args, int fd)
{
	int	i;

	i = 0;
	if (*format == '%')
		i += ft_putchar_fd('%', fd);
	else if (*format == 'c')
		i += ft_putchar_fd(va_arg(args, int), fd);
	else if (*format == 'p')
		i += ft_forpointer(va_arg(args, void *), fd);
	else if (*format == 's')
		i += ft_putstr_fd(va_arg(args, char *), fd);
	else if (*format == 'd' || *format == 'i')
		i += ft_putnbr_fd(va_arg(args, int), fd);
	else if (*format == 'u')
		i += ft_unsigned_putnbr(va_arg(args, unsigned int), fd);
	else if (*format == 'x' || *format == 'X')
		i += ft_hexadecimal(va_arg(args, unsigned int), *format, fd);
	return (i);
}

/**
 * @brief A simplified printf function that outputs formatted data to a given file descriptor.
 *
 * Parses the format string and handles conversion specifiers to print
 * formatted output to the file descriptor 'fd'. Supports specifiers: %, c, p, s,
 * d, i, u, x, and X. Returns the total number of characters printed.
 *
 * @param fd The file descriptor where the output is written.
 * @param format The null-terminated format string.
 * @param ... Variable arguments corresponding to format specifiers.
 * @return int The total number of characters printed.
 */
int	ft_printf(int fd, const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (count);
			count += check_format(format, args, fd);
		}
		else
			count += ft_putchar_fd(*format, fd);
		format++;
	}
	va_end(args);
	return (count);
}
