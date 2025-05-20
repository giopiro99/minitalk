/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:53:51 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:02:56 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Calculates the length of a NULL-terminated matrix of strings.
 *
 * Counts how many strings are in the matrix until the NULL terminator.
 * Returns -1 if the matrix pointer is NULL.
 *
 * @param matrix The NULL-terminated matrix of strings.
 * @return int The number of strings in the matrix, or -1 if matrix is NULL.
 */
int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (-1);
	while (matrix[i])
		i++;
	return (i);
}
