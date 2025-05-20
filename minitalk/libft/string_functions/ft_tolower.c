/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:10:08 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:19:18 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * If the input character `c` is an uppercase ASCII letter (A-Z),
 * it converts it to the corresponding lowercase letter (a-z).
 * Otherwise, returns the character unchanged.
 *
 * @param c The character to convert.
 * @return int The lowercase equivalent if uppercase, else `c` unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*int	main(void)
{
	char	j = 'A';
	j = ft_tolower(j);
	write(1, &j, 1);
}*/
