/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:20:26 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/20 17:48:35 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

void				read_and_store(t_list **store, int *p_read, int fd);
char				*get_next_line(int fd);

t_list				*ft_lst_last(t_list *lst);
t_list				*ft_lstnew(char *content);
void				ft_lstadd_back(t_list **store, t_list *lst);
void				add_to_store(t_list **store, char *content);

t_list				*find_newline_node(t_list **store);
t_list				*find_newline_node(t_list **store);
// int					found_newline(t_list *store);

char				*ft_strdup(char *content);
int					ft_strlen(char *str);
void				ft_print_lst(t_list **store);
#endif