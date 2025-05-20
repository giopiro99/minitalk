/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:30:43 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:08:28 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks whether a character is a decimal digit.
 *
 * Returns 1 if the character 'c' is a digit (i.e., between '0' and '9'),
 * and 0 otherwise.
 *
 * @param c The character to check, represented as an integer.
 * @return int 1 if 'c' is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d",ft_isdigit('c'));
}*/
