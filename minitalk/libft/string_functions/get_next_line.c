/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:43 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:20:32 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * get_next_line - reads a line from a file descriptor (fd).
 *
 * Main function: get_next_line(int fd)
 * - Returns the next complete line (ending with '\n' or EOF) read from the file descriptor `fd`.
 * - Internally keeps track of leftover data (using the static variable `rest`) to handle partial reads,
 *   allowing it to read files of any size line by line.
 *
 * Helper functions:
 *
 * ft_putline:
 * - Reads from `fd` in chunks of size BUFFER_SIZE.
 * - Accumulates the read data in `*result`, concatenating buffers.
 * - Stops reading once a newline '\n' is found or EOF is reached.
 * - On read error, frees `*result` and returns NULL.
 *
 * ft_getrest:
 * - After getting a full line, extracts the leftover data after the first '\n'.
 * - Returns this leftover string to be used on the next call to get_next_line.
 * - Truncates the current line at the newline so only one line is returned.
 * - Returns NULL if no leftover exists.
 *
 * get_next_line:
 * - Allocates a buffer for reading.
 * - Checks validity of `fd` and BUFFER_SIZE.
 * - Uses ft_putline to read and accumulate data from `fd`.
 * - Updates static `rest` with leftover data after the current line.
 * - Returns the line read or NULL on error or EOF.
 *
 * Notes:
 * - BUFFER_SIZE is set to 1 (reading one byte at a time).
 * - This implementation handles files of any size, returning one line per call without data loss.
 * - Memory allocated for lines and leftover data must be managed properly by the caller.
 */

#define BUFFER_SIZE	1

static char	*ft_putline(int fd, char **result, char *buffer)
{
	ssize_t	bt_read;
	char	*tmp;

	while (1)
	{
		bt_read = read(fd, buffer, BUFFER_SIZE);
		if (bt_read == -1)
		{
			free(*result);
			*result = NULL;
			return (NULL);
		}
		else if (bt_read == 0)
			break ;
		buffer[bt_read] = '\0';
		if (!*result)
			*result = ft_strdup("");
		tmp = *result;
		*result = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*result);
}

static char	*ft_getrest(char *line)
{
	ssize_t	i;
	char	*rest;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_putline(fd, &rest, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	rest = ft_getrest(line);
	return (line);
}
/* int main()
{
	char	*line;
	int	fd;

	fd = open("text.txt", O_WRONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			return(1);
		printf("%s", line);
		free(line);
	}
	close(fd);
} */
