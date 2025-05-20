/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:35:05 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:16:18 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*char	f(unsigned int index, char s)
{
	if (s >= 'a' && s <= 'z')
		return (s - 32 + index);
	return (s);
}*/
/**
 * @brief Creates a new string by applying a function to each character of the input string.
 *
 * Allocates memory for a new string and applies the function `f` to each character of
 * the input string `s`, passing the character’s index and the character itself.
 * The result of the function is stored in the new string at the corresponding position.
 *
 * @param s The input null-terminated string.
 * @param f The function to apply, which takes an unsigned int (index) and a char,
 *          and returns a char.
 * @return char* A newly allocated string with the transformed characters, or NULL if allocation fails or inputs are invalid.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int	main(void)
{
	const char	s[] = "ciao";
	printf("%s", ft_strmapi(s, (*f));
}*/
