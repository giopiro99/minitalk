/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:22:02 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:02:13 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Duplicates a matrix of strings (NULL-terminated array of strings).
 *
 * Counts the number of strings in the original matrix, allocates memory for the new matrix,
 * and duplicates each string using ft_strdup. The duplicated matrix is NULL-terminated.
 * In case of allocation failure, frees already allocated memory and returns NULL.
 *
 * @param matrix The matrix of strings to duplicate.
 * @param dup_matrix Pointer to the duplicated matrix (input is ignored, used for output).
 * @return char** Pointer to the duplicated matrix, or NULL on failure.
 */
char	**ft_dup_matrix(char **matrix, char **dup_matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	dup_matrix = malloc(sizeof(char *) * (i + 1));
	if (!dup_matrix)
	{
		free(dup_matrix);
		return (NULL);
	}
	i = 0;
	while (matrix[i] != NULL)
	{
		dup_matrix[i] = ft_strdup(matrix[i]);
		if (!dup_matrix)
			return (free(dup_matrix), NULL);
		i++;
	}
	dup_matrix[i] = NULL;
	return (dup_matrix);
}
