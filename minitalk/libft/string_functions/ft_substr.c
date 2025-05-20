/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:06:52 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:18:45 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Extracts a substring from a given string.
 *
 * Allocates and returns a new string which is a substring of `s`, starting at index `start`
 * and with maximum length `len`. If `start` is beyond the end of `s`, returns an empty string.
 * If `len` goes beyond the end of `s`, the substring will be truncated accordingly.
 * Returns NULL if `s` is NULL or memory allocation fails.
 *
 * @param s The original string.
 * @param start The starting index for the substring.
 * @param len The maximum length of the substring.
 * @return char* Newly allocated substring, or NULL on failure.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	start1;
	char	*str;

	start1 = (size_t)start;
	if (s == NULL)
		return (NULL);
	if (start1 >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
/*int main()
{
	char	s[] = "ciaociaoromaciao";
	printf("%s", ft_substr(s, 8, 4));
}*/
