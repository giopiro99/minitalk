/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:39:47 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:05:28 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Scans the initial 'n' bytes of the memory area pointed to by 's' for the first occurrence of 'c'.
 *
 * Searches for the first occurrence of the byte 'c' (converted to unsigned char)
 * in the first 'n' bytes of the memory area pointed to by 's'.
 *
 * @param s Pointer to the memory area to be scanned.
 * @param c Byte value to search for (converted to unsigned char).
 * @param n Number of bytes to examine.
 * @return void* Pointer to the matching byte within 's', or NULL if no match is found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;
	size_t			i;

	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char s[] = "ciao";
	int c = 105;
	void *b = ft_memchr(s, c, 1);
	printf("%p", b);
}*/
