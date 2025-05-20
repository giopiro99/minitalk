/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:16:26 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:51:11 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Converts a string to an integer.
 *
 * Parses the string `nptr`, skipping any leading whitespace, then reads
 * an optional sign (+ or -), followed by numerical digits, converting
 * them into an integer value.
 *
 * @param nptr Pointer to the null-terminated string to convert.
 * @return The converted integer value. If the string does not contain
 *         any valid integer, returns 0.
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
/*int	main(void)
{
	printf("%d", ft_atoi("     -----13e24abc"));
}*/
