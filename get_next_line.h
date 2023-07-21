/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:20:26 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/21 19:36:19 by azaaza           ###   ########.fr       */
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
	struct s_list	*prev;
}					t_list;

void				read_and_store(t_list **store, int fd);
char				*get_next_line(int fd);

t_list				*ft_lst_last(t_list *lst);
t_list				*ft_lstfirst(t_list *lst);
t_list				*ft_lstnew(char *content);
void				ft_lstadd_back(t_list **store, t_list *lst);
void				add_to_store(t_list **store, char *content);

char				*get_line(t_list **store, int count);
void				lstclear_prev(t_list *node);
// int					found_newline(t_list *store);

size_t				ft_strncat(char *dest, char *src, size_t n);
char				*ft_strdup(char *content);
int					ft_strlen(const char *str);
void				ft_print_lst(t_list **store);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, char *src, size_t dest_size);
#endif