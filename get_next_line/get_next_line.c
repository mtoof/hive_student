/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:07:18 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/29 18:30:13 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

static char	*ft_join(char	*buffer, char	*stash)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, stash);
	free(buffer);
	return (tmp);
}

static char	*found_new_line(char	*buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*extract_next_line(char	*buffer)
{
	int		index_buffer;
	int		index_newline;
	char	*new_line;

	index_buffer = 0;
	while (buffer[index_buffer] && buffer[index_buffer] != '\n')
		index_buffer++;
	if (!buffer[index_buffer])
	{
		free(buffer);
		return (NULL);
	}
	new_line = ft_calloc((ft_strlen(buffer) - index_buffer + 1), sizeof(char));
	index_buffer++;
	index_newline = 0;
	while (buffer[index_buffer] && buffer[index_buffer] != '\n')
		new_line[index_newline++] = buffer[index_buffer++];
	free(buffer);
	return (new_line);
}

static char	*read_and_stash(int fd,	char *buffer)
{
	int		readed_char;
	char	*stash;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	readed_char = 1;
	stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (readed_char > 0)
	{
		readed_char = read(fd, stash, BUFFER_SIZE);
		if (readed_char == -1)
			return (NULL);
		// stash[readed_char] = 0;
		buffer = ft_join(buffer, stash);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(stash);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_and_stash(fd, buffer);
	if (!buffer)
		return (NULL);
	line = found_new_line(buffer);
	if (!line)
		return (NULL);
	buffer = extract_next_line(buffer);
	if (!buffer)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("two_lines_with_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}
