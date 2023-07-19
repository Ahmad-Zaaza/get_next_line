/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:46:35 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/19 00:19:46 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd) {
  static t_list *store;
  char *line;
  int bytes_read;

  // check if fd is negative, if BUFFER_SIZE is negative, or we don't have
  // permissions to read the file
  if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
    return (NULL);
  bytes_read = 1;
  line = NULL;

  // 1. Read from fd until the buffer size and store.
  read_and_store(&store, &bytes_read, fd);

  ft_print_lst(&store);
  return line;
}

void read_and_store(t_list **store, int *p_read, int fd) {
  char *buffer;
  buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
  if (!buffer)
    return;

  while ((*p_read = read(fd, buffer, BUFFER_SIZE - 1))) {
    printf("read: %d\n", *p_read);
    buffer[*p_read] = '\0';
    add_to_store(store, buffer);
  }
  // add the buffer to the list
}

int found_newline(t_list *store) {
  t_list *tmp;
  int i;

  i = 0;
  store = tmp;
  while (tmp) {
    i = 0;
    while (tmp->content[i]) {
      if (tmp->content[i] == '\n') {
        return (1);
      }
      i++;
    }
    tmp = tmp->next;
  }
  return (0);
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
    // printf("%s\n", line);
  }
  free(line);
  return (0);
}