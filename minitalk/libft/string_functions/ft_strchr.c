/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:59:13 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:13:09 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * Searches the string 's' for the first occurrence of the character 'c'.
 * If 'c' is found, returns a pointer to its position in the string.
 * If 'c' is the null terminator '\0', returns a pointer to the end of the string.
 * Returns NULL if the character is not found.
 *
 * @param s The null-terminated string to search in.
 * @param c The character to locate (interpreted as unsigned char).
 * @return char* Pointer to the first occurrence of 'c' in 's', or NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	k;

	k = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == k)
			return ((char *)&s[i]);
		i++;
	}
	if (k == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*int	main()
{
	const char s[] = "";
	printf("%s", ft_strchr(s, '\0'));
}*/
