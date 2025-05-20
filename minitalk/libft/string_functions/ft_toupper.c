/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:19:29 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * If the input character `c` is a lowercase ASCII letter (a-z),
 * it converts it to the corresponding uppercase letter (A-Z).
 * Otherwise, returns the character unchanged.
 *
 * @param c The character to convert.
 * @return int The uppercase equivalent if lowercase, else `c` unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*int	main(void)
{
	char	j = 'a';
	j = ft_toupper(j);
	write(1, &j, 1);
}*/
