/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:03:26 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:14:01 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Applies a function to each character of a string, with index.
 *
 * Iterates over the string 's' and applies the function 'f' to each character,
 * passing the current index and a pointer to the character.
 *
 * @param s The null-terminated string to iterate over.
 * @param f The function to apply to each character, which takes the index
 *          and a pointer to the character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
