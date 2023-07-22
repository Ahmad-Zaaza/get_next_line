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

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct s_list {
  char *content;
  struct s_list *next;
} t_list;

char *get_next_line(int fd);

t_list *ft_lstlast(t_list *lst);
t_list *ft_lstnew(char *content);

void ft_lstadd_back(t_list **store, t_list *lst);

char *get_line(t_list **store);
char *fill_and_purge(t_list **store, int node_index);
void read_and_store(t_list **store, int fd);

char *ft_strdup(char *content);
int ft_strlen(const char *str);

#endif