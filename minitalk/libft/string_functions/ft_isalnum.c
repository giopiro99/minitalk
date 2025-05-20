/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:41:37 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:07:25 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks whether a character is alphanumeric.
 *
 * Returns 1 if the character 'c' is either a letter (uppercase or lowercase)
 * or a digit. Returns 0 otherwise.
 *
 * @param c The character to check, represented as an integer.
 * @return int 1 if 'c' is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d",ft_isalnum(63));
}*/
