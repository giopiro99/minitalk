/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:12:14 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:09:21 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks whether a character is a whitespace character.
 *
 * Returns 1 if the character 'c' is a whitespace character:
 * space (32), horizontal tab (9), newline (10), vertical tab (11),
 * form feed (12), or carriage return (13). Returns 0 otherwise.
 *
 * @param c The character to check.
 * @return int 1 if 'c' is a whitespace character, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
