/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:31:44 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:04:20 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * Iterates through the string 's', counting sequences of characters
 * separated by the delimiter 'split'.
 *
 * @param s The input string to analyze.
 * @param split The delimiter character used to split the string.
 * @return int The number of words found.
 */
static int	count_words(char const *s, char split)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == split)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != split && s[i] != '\0')
			i++;
	}
	return (count);
}

/**
 * @brief Copies a substring (word) from the input string.
 *
 * Allocates memory and copies characters from index start_w to end_w (exclusive)
 * into a new null-terminated string.
 *
 * @param s The input string.
 * @param start_w The starting index of the word.
 * @param end_w The ending index (exclusive) of the word.
 * @return char* Newly allocated string containing the copied word, or NULL if allocation fails.
 */
static char	*copy_w(const char *s, int start_w, int end_w)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(end_w - start_w + 1);
	if (!word)
		return (NULL);
	while (start_w < end_w)
		word[i++] = s[start_w++];
	word[i] = '\0';
	return (word);
}

/**
 * @brief Frees an array of strings up to a given index.
 *
 * Frees each string in the array from index 0 up to j-1, then frees the array itself.
 * Does nothing if the array pointer is NULL.
 *
 * @param arr The array of strings to free.
 * @param j Number of strings to free.
 */
static void	fclean(char **arr, int j)
{
	if (!arr)
	{
		while (--j >= 0)
			free(arr[j]);
		free(arr);
	}
	return ;
}

/**
 * @brief Splits a string into an array of strings based on a delimiter.
 *
 * Allocates and returns a NULL-terminated array of strings, each containing
 * a substring of 's' separated by the character 'split'. Uses helper functions
 * to count words, copy substrings, and clean up in case of errors.
 *
 * @param s The input string to split.
 * @param split The delimiter character.
 * @return char** The array of split strings, or NULL if allocation fails.
 */
char	**ft_split(char const *s, char split)
{
	char	**arr;
	int		i;
	int		start_w;
	int		j;

	i = 0;
	j = 0;
	arr = malloc((count_words(s, split) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == split)
			i++;
		else
		{
			start_w = i;
			while (s[i] != '\0' && s[i] != split)
				i++;
			arr[j++] = copy_w(s, start_w, i);
			fclean(arr, j);
		}
	}
	arr[j] = NULL;
	return (arr);
}
/*int main()
{
	const char s[] = "      split       this for   me  !       " ;
	char	c = ' ';
	int	j = 0;
	char	**arr = ft_split(s, ' ');
	while (arr[j] != NULL)
	{
		printf("%s\n", arr[j]);
		free(arr[j]);
		j++;
	}
	free(arr);
	return (0);
}*/
