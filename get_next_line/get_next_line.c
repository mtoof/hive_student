/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:58:50 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/26 23:34:44 by sepehr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

t_list	*ft_lstlast(t_list *list)
{
	t_list	*current;

	current = list;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	add_to_list(t_list **list, char *buffer, int readed_chr)
{
	int		index;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed_chr + 1));
	if (new_node->content == NULL)
		return ;
	index = 0;
	while (buffer[index] && index < readed_chr)
	{
		new_node->content[index] = buffer[index];
		index++;
	}
	new_node->content[index] = '\0';
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = new_node;
}

int		found_new_line(t_list *tmp_list)
{
	int		index;
	t_list	*current;

	if (!tmp_list)
		return (0);
	current = ft_lstlast(tmp_list);
	index = 0;
	while (current->content[index])
	{
		if (current->content[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

void	read_and_buffer(int fd, t_list **list)
{
	char	*buffer;
	int		readed_chr;

	readed_chr = 1;
	while (!found_new_line(*list) && readed_chr != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readed_chr = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && readed_chr == 0) || readed_chr == -1)
		{
			free(buffer);
			return ;
		}
		buffer[readed_chr] = '\0';
		add_to_list(list, buffer, readed_chr);
		free(buffer);
	}
}

void	generate_line(char **line, t_list *tmp_list)
{
	int	i;
	int	len;

	len = 0;
	while(tmp_list)
	{
		i = 0;
		while(tmp_list->content[i])
		{
			if (tmp_list->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		tmp_list = tmp_list->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	extract_line(t_list *temp_list, char	**line)
{
	int	index_content;
	int	index_line;

	if (temp_list == NULL)
		return ;
	generate_line(line, temp_list);
	if (!*line)
		return ;
	index_line = 0;
	while(temp_list)
	{
		index_content = 0;
		while(temp_list->content[index_content])
		{
			if (temp_list->content[index_content] == '\n')
			{
				(*line)[index_line++] = temp_list->content[index_content];
				break;
			}
			(*line)[index_line++] = temp_list->content[index_content++];
		}
		temp_list = temp_list->next;
	}
	(*line)[index_line] = '\0';
}

void	free_tmp_list(t_list *tmp_list)
{
	t_list	*current;
	t_list	*next;

	current = tmp_list;
	while(current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	clean_list(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (list == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*list);
	i = 0;
	while(last->content[i] && last->content[i] != '\n')
		i++;
	if(last->content[i] && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ft_strlen(last->content) - i) + 1);
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_tmp_list(*list);
	*list = clean_node;
}

char	*get_next_line(int fd)
{
	static t_list	*temp_list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	temp_list = NULL;
	read_and_buffer(fd, &temp_list);
	if (temp_list == NULL)
		return (NULL);
	extract_line(temp_list, &line);
	clean_list(&temp_list);
	if (line[0] == '\0')
	{
		free_tmp_list(temp_list);
		temp_list = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test/two_lines_with_nl", O_RDONLY);
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
