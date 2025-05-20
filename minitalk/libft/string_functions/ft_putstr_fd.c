/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:10:34 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:12:40 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Writes a null-terminated string to the specified file descriptor.
 *
 * Outputs the string 's' to the file descriptor 'fd' character by character.
 *
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 * @return int The total number of bytes written.
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		count += write(fd, &s[i], 1);
		i++;
	}
	return (count);
}
