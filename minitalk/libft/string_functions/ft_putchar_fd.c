/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:09:23 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:11:45 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Writes a single character to the specified file descriptor.
 *
 * Outputs the character 'c' to the file descriptor 'fd' using the write system call.
 *
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 * @return int The number of bytes written (1 on success), or -1 on error.
 */
int	ft_putchar_fd(char c, int fd)
{
	int	i;

	i = 0;
	i += write(fd, &c, 1);
	return (i);
}
