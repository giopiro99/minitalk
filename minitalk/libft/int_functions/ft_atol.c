/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:11:26 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:52:08 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Converts a string to an long integer.
 *
 * Parses the string `str`, skipping any leading whitespace, then reads
 * an optional sign (+ or -), followed by numerical digits, converting
 * them into an integer value.
 *
 * @param str Pointer to the null-terminated string to convert.
 * @return The converted integer value. If the string does not contain
 *         any valid integer, returns 0.
 */
long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
