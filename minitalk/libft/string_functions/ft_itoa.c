/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:58:16 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:11:00 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Calculates the number of characters needed to represent an integer as a string.
 *
 * Accounts for a possible negative sign and returns 1 if the number is 0.
 *
 * @param n The integer to evaluate.
 * @return int The number of characters required to represent 'n' as a string.
 */
static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/**
 * @brief Copies a null-terminated string into another buffer.
 *
 * Assumes 'str' has enough space to hold 's2'. Appends a null terminator.
 *
 * @param str Destination buffer.
 * @param s2 Source null-terminated string.
 * @return char* Pointer to the destination buffer 'str'.
 */
static char	*fstrcpy(char *str, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Returns a string representation of the minimum integer value.
 *
 * Handles the edge case of INT_MIN (-2147483648) which cannot be
 * negated in a 32-bit integer range. The returned string is allocated
 * dynamically and must be freed by the caller.
 *
 * @return char* A newly allocated string containing "-2147483648",
 * or NULL if memory allocation fails.
 */
static char	*int_min(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	fstrcpy(str, "-2147483648");
	return (str);
}

/**
 * @brief Fills a string buffer with the digits of an integer.
 *
 * Assumes the buffer 'str' has enough space for the digits and handles
 * negative numbers by prepending a minus sign. The digits are filled
 * from the end of the string toward the beginning.
 *
 * @param str Pointer to the destination buffer.
 * @param i Index from which to start inserting digits (from the end).
 * @param n The integer to convert.
 * @return char* Pointer to the filled string buffer 'str'.
 */
static char	*fget_itoa(char *str, int i, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * Handles negative numbers, including the special case of INT_MIN (-2147483648),
 * which cannot be directly negated. Allocates sufficient memory to store the
 * resulting string, including the null terminator.
 *
 * @param n The integer to convert.
 * @return char* A pointer to the newly allocated string representing the integer,
 * or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	len = get_len(n);
	i = len - 1;
	if (n == -2147483648)
		return (int_min());
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	fget_itoa(str, i, n);
	str[len] = '\0';
	return (str);
}

/*int	main(void)
{
//modulo 10 per prendere ultima cifra + 48 per convertire in stringa
//i-- perche parto dal fondo del numero per poter prendere tutte le cifre
//, se partissi da i = 0 perderei dei numeri
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(100));
	printf("%s\n", ft_itoa(-100));
	printf("%s\n", ft_itoa(1000));
	printf("%s\n", ft_itoa(-1000));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(999999999));
	printf("%s", ft_itoa(-999999999));
}*/
