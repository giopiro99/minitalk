/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:42:17 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:15:11 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @brief Returns the length of a null-terminated string.
 *
 * Counts the number of characters in 'str' until the null terminator.
 *
 * @param str The input null-terminated string.
 * @return size_t The length of the string excluding the null terminator.
 */
static	size_t	len(const char *str)
{
	size_t	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

/**
 * @brief Concatenates 'src' to the end of 'dst' with size limit.
 *
 * Appends string 'src' to the end of 'dst', ensuring the total length
 * does not exceed 'size' (including null terminator).
 * Returns the total length of the string it tried to create,
 * i.e., initial length of 'dst' plus length of 'src'.
 * If 'size' is less than or equal to initial length of 'dst',
 * returns 'size' plus length of 'src' without concatenation.
 *
 * @param dst Destination buffer containing a null-terminated string.
 * @param src Source string to append.
 * @param size Total size of the destination buffer.
 * @return size_t The length of the string it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	len_dst;
	size_t	len_src;

	k = 0;
	len_dst = len(dst);
	len_src = len(src);
	i = len_dst;
	if (len_dst >= size || size < 1)
		return (size + len_src);
	while (src[k] != '\0' && i < size - 1)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
/*int	main()
{
	char d[]="ciaoe";
	char s[]="mondo";
	printf("%zu", ft_strlcat(d, s, 9));
	printf("%s", d);
}*/
