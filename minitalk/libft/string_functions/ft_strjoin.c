/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:38:03 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:14:33 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * Allocates memory to create a new string that is the
 * concatenation of 's1' followed by 's2'.
 * Returns NULL if either input is NULL or if allocation fails.
 *
 * @param s1 The first null-terminated string.
 * @param s2 The second null-terminated string.
 * @return char* Pointer to the newly allocated concatenated string,
 *               or NULL on failure.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
/*int main()
{
	const char str[] = "tua madre ";
	const char str2[] = "saluta i bambini..";
	printf("%s", ft_strjoin(str, str2));
}*/
