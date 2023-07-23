/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:46:35 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/23 22:14:06 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd) {
  static t_table_item table[MAX_FD] = {0};
  char *buffer;
  int readed;
  t_table_item *item;

  buffer = 0;
  if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
    return (NULL);
  item = &table[fd];
  if (item->init == 0) {
    init_queue(&item->queue);
    item->init = 1;
  }
  if (has_newline(&item->queue))
    return (get_line(&item->queue));
  buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
  if (!buffer)
    return (NULL);
  readed = read(fd, buffer, BUFFER_SIZE);
  buffer[readed] = '\0';
  return (handle_read(fd, readed, buffer, &item->queue));
}

char *handle_read(int fd, int readed, char *buffer, t_queue *queue) {
  int i;

  if (readed > 0) {
    i = 0;
    while (buffer[i]) {
      push_queue(queue, buffer[i]);
      i++;
    }
    free(buffer);
    return (get_next_line(fd));
  } else {
    free(buffer);
    if (queue_empty(queue))
      return (NULL);
    else
      return (get_rest(queue));
  }
}

// int main(void) {
//   int fd;
//   char line[BUFFER_SIZE] = {0};
//   fd = open("./test.txt", O_RDONLY);

//   printf("%s", get_next_line(fd));
//   read(fd, line, 42);
//   line[41] = 0;
//   printf("%s", line);
//   printf("%s", get_next_line(fd));
//   //   free(line);
//   return (0);
// }
// int main(void) {
//   int fd;
//   //   char line[BUFFER_SIZE] = {0};
//   fd = open("./test.txt", O_RDONLY);

//   printf("%s", get_next_line(fd));
//   printf("%s", get_next_line(fd));
//   printf("%s", get_next_line(fd));
//   printf("%s", get_next_line(fd));

//   //   printf("%s", get_next_line(fd));
//   //   free(line);
//   return (0);
// }