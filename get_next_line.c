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
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

char *get_next_line(int fd) {
  t_list *store;
  char *line;
  int bytes_read;

  if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
    return (NULL);
  bytes_read = 1;
  line = NULL;

  read_and_store(&store, &bytes_read);

  // Read from fd and store
  return line;
}

void read_and_store(t_list **store, int *p_read) {
  char *buffer;
  buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
  if (!buffer)
    return;
  while ((*p_read = read(fd, buffer, BUFFER_SIZE - 1))) {
    buffer[*p_read] = '\0';
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