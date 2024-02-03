/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:32:39 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/02 21:19:30 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


char				*get_next_line(int fd);
t_list				*ft_lstlast(t_list *lst);
void				read_and_store(int fd, t_list **lst);
void				add_to_lst(t_list **lst, char *buff, int nb_read);
int					found_newline(t_list *lst);
void				create_line(char **line, t_list *lst);
void				copy_line(t_list *lst, char **line);
void				free_all(t_list *lst);
void				clear_lst(t_list **lst);
#endif
