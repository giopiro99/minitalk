/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:17:07 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:17:25 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @brief Finds the last occurrence of the character `c` in the string `s`.
 *
 * Searches the string `s` from the end to the beginning for the character `c`.
 * If found, returns a pointer to the last occurrence of `c` in `s`. If `c` is
 * the null terminator, returns a pointer to the end of the string. Returns NULL
**/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	k;

	k = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == k)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*int	main()
{
	const char s[] = "\0";
	printf("%s", ft_strchr(s, 'f'));
}*/
