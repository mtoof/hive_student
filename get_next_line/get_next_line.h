/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:02 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/20 12:30:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

//gnl
char	*get_next_line(int fd);
void	clean_list(t_list **list);
void	extract_line(t_list *list, char	**line);
void	read_and_save(int fd, t_list **list, int *readed);
void	add_to_list(t_list **list, char *buffer, int readed);
//gnl_utils
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *list);
int		found_new_line(t_list *list);
void	free_list(const char *str);
void	generate_new_line(char **line, t_list *list);

#endif