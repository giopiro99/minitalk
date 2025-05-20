/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:56:18 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:05:10 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Allocates memory for an array and initializes it to zero.
 *
 * Allocates memory for an array of 'nmemb' elements of 'size' bytes each.
 * If both 'nmemb' and 'size' are zero, allocates 1 byte to avoid undefined behavior.
 * The allocated memory is initialized to zero.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return void* Pointer to the allocated and zero-initialized memory, or NULL on failure.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 && size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	else
		return (ft_memset(ptr, 0, nmemb * size));
}
/*int main()
{
	char *a = (char *)ft_calloc(5, sizeof(char));
	printf("%s", a);
	if (a != NULL)
		free(a);
	//per provarlo cambia 48 con altro
}*/
