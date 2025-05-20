/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:48:52 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:15:33 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @brief Copies up to size - 1 characters from the string src to dst,
 *        null-terminating the result.
 *
 * Copies characters from 'src' to 'dst' until either 'size - 1' characters
 * are copied or the null terminator of 'src' is reached.
 * The destination string is always null-terminated if 'size' is greater than 0.
 * Returns the total length of 'src'; this allows detection of truncation
 * by comparing the return value with 'size'.
 *
 * @param dst Destination buffer where the string is copied.
 * @param src Source null-terminated string to copy from.
 * @param size Total size of the destination buffer.
 * @return size_t Length of the source string 'src'.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

/*int	main()
{
	char d[5];
	char s[4] = {'c','h','h','h','k'};
	printf("%zu", ft_strlcpy(d, s, 3));
	printf("%s", d);


}*/
