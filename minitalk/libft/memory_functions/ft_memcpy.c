/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:47:45 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:05:57 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 *
 * The memory areas must not overlap. If both 'dest' and 'src' are NULL and 'n' > 0,
 * the function returns NULL to indicate an invalid operation.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return void* Pointer to the destination memory area 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
/*int	main()
{
	char src[] = "ciao";
	char dest[10];
	//ft_memcpy(NULL, NULL, 0);
	memcpy(NULL, NULL, 0);
	printf("%s", dest);
}*/
