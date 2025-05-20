/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:48:22 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:16:35 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Compares up to n characters of two strings.
 *
 * Compares the strings `s1` and `s2` lexicographically up to `n` characters or until
 * a null-terminator is reached. Returns the difference between the first differing
 * characters cast to unsigned char, or zero if the compared parts are equal.
 *
 * @param s1 Pointer to the first null-terminated string.
 * @param s2 Pointer to the second null-terminated string.
 * @param n Maximum number of characters to compare.
 * @return int Negative, zero, or positive value if `s1` is less than, equal to, or greater than `s2` respectively.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	if (i != n)
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	return (0);
}
/*int	main(void)
{
	const char s1[] = "ciao";
	const char s2[] = "ciao";
	int x = ft_strncmp(s1, s2, 10);
	printf("%d" , x);
}*/
