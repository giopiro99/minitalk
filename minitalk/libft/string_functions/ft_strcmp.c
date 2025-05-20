/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:14:41 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:13:23 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Compares two null-terminated strings lexicographically.
 *
 * Compares the strings 's1' and 's2' character by character.
 * Returns the difference between the first differing characters
 * interpreted as unsigned char, or zero if the strings are equal.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return int A negative, zero, or positive value if 's1' is less than,
 * equal to, or greater than 's2', respectively.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}
