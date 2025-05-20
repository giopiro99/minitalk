/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:47:23 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:08:10 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks whether a character is an ASCII character.
 *
 * Returns 1 if the character 'c' is part of the standard ASCII set
 * (i.e., in the range 0 to 127 inclusive). Returns 0 otherwise.
 *
 * @param c The character to check, represented as an integer.
 * @return int 1 if 'c' is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d",ft_isalnum(63));
}*/
