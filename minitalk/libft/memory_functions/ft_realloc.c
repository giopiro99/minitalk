/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:56:21 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/05/20 15:07:01 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Reallocates a NULL-terminated matrix of strings to a new size.
 *
 * Allocates a new matrix of size 'new_size' and copies up to 'old_size' existing
 * strings from the original matrix using deep copies (ft_strdup). Frees the old matrix
 * after copying. The new matrix is NULL-terminated.
 *
 * @param matrix The original NULL-terminated matrix of strings.
 * @param new_size The new desired size (number of rows) for the matrix.
 * @param old_size The number of strings to copy from the original matrix.
 * @return char** A pointer to the newly allocated and copied matrix, or NULL on failure.
 */
char	**ft_realloc_mtx(char **matrix, size_t new_size, size_t old_size)
{
	char	**new_matrix;
	size_t	i;

	i = 0;
	new_matrix = malloc(sizeof(char *) * (new_size + 1));
	if (!new_matrix)
		return (NULL);
	while (i < old_size && matrix[i] != NULL)
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i] = NULL;
	ft_free_matrix(matrix);
	return (new_matrix);
}
