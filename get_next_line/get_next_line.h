/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:02 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/26 22:57:29 by sepehr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

//gnl
char				*get_next_line(int fd);
void				clean_list(t_list **list);
void				extract_line(t_list *temp_list, char **line);
void				read_and_buffer(int fd, t_list **list);
void				add_to_list(t_list **list, char *buffer, int readed_chr);
//gnl_utils
size_t				ft_strlen(const char *s);
t_list				*ft_lstlast(t_list *list);
int					found_new_line(t_list *tmp_list);
void				free_tmp_list(t_list *tmp_list);
void				generate_line(char **line, t_list *tmp_list);

#endif