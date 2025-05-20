/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:23:01 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:16:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Locates the first occurrence of the substring `little` in the string `big`,
 *        searching only up to `len` characters.
 *
 * Searches for the first occurrence of the null-terminated string `little` within the
 * first `len` characters of the string `big`. If `little` is an empty string, returns
 * `big`. If `little` is not found within `len` characters, returns NULL.
 *
 * @param big Pointer to the null-terminated string to be searched.
 * @param little Pointer to the null-terminated substring to find.
 * @param len Maximum number of characters to search in `big`.
 * @return char* Pointer to the beginning of the located substring in `big`, or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	if (big[0] == '\0' || len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char b[] = "ciromociroaoroikmaciaoroma";
	char l[] = "roma";
	printf("%s", ft_strnstr(b, l ,24));
}*/
