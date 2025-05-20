/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:55:56 by lemarino          #+#    #+#             */
/*   Updated: 2025/05/20 15:18:30 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	tft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static char	*tft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == cc)
			return ((char *)(s + i));
		i++;
	}
	if (cc == '\0')
		return ((char *)(s + i));
	else
		return (NULL);
}

/**
 * @brief Trims characters from the start and end of a string.
 *
 * Removes all characters found in `set` from the beginning and the end of the string `s1`.
 * Returns a newly allocated string without the trimmed characters. If `s1` or `set` is NULL,
 * returns NULL.
 *
 * @param s1 The original string to trim.
 * @param set A string containing characters to be trimmed from `s1`.
 * @return char* Newly allocated trimmed string, or NULL on allocation failure or invalid input.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && tft_strchr(set, s1[i]))
		i++;
	j = tft_strlen((char *)s1);
	while (j > i && tft_strchr(set, s1[j - 1]))
		j--;
	len = j - i;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (i < j)
		str[len++] = s1[i++];
	str[len] = '\0';
	return (str);
}
/* int	main()
{
	char	*tizio = "c e 'era uno  c ";
	char	*caio = "ceo ";

	printf("%s\n", ft_strtrim(tizio, caio));
} */
