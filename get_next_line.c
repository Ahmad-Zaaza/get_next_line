/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:46:35 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/21 19:38:30 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd) {
  static t_list *store;
  t_list *newline_node;
  int node_index;
  char *line;

  // check if fd is negative, if BUFFER_SIZE is negative, or we don't have
  // permissions to read the file
  if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
    return (NULL);
  node_index = 0;
  line = NULL;
  // 1. Read from fd until the buffer size and store.
  read_and_store(&store, fd);
  line = get_line(&store);
  return (line);
}

char *get_line(t_list **store) {
  t_list *current;
  int count;

  current = *store;
  count = 1;

  while (current) {
    if (current->content[0] == '\n' || !current->next) {
      return fill_and_purge(store, count);
    }
    current = current->next;
    count++;
  }
  return (NULL);
}
char *fill_and_purge(t_list **store, int node_index) {
  t_list *tmp;
  int i;
  char *line;

  line = (char *)malloc(sizeof(char) * node_index);
  if (!line)
    return (NULL);
  i = 0;
  line[node_index] = '\0';
  while (*store) {
    if ((*store)->content[0] == '\n') {
      tmp = (*store)->next;
      free((*store)->content);
      free((*store));
      *store = tmp;
      break;
    } else {
      line[i] = (*store)->content[0];
      tmp = (*store)->next;
      free((*store)->content);
      free((*store));
      *store = tmp;
      i++;
    }
  }
  return (line);
}
void read_and_store(t_list **store, int fd) {
  char *buffer;
  int readed;
  int i;

  buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
  if (!buffer)
    return;
  while ((readed = read(fd, buffer, BUFFER_SIZE))) {
    i = 0;
    buffer[readed] = '\0';
    while (buffer[i]) {
      ft_lstadd_back(store, ft_lstnew(ft_strdup(&buffer[i])));
      i++;
    }
  }
}

int main(void) {
  int fd;
  char *line;
  fd = open("./test.txt", O_RDONLY);

  while (1) {
    line = get_next_line(fd);
    if (!line) {
      break;
    }
    printf("%s\n", line);
  }
  free(line);
  return (0);
}