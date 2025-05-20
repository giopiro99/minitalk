/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:53 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:08:55 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks whether a character is printable.
 *
 * Returns 1 if the character 'c' is a printable character,
 * including space (i.e., in the ASCII range 32 to 126).
 * Returns 0 otherwise.
 *
 * @param c The character to check, represented as an integer.
 * @return int 1 if 'c' is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d",ft_isprint(63));
}*/
