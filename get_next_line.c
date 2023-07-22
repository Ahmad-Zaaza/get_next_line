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
  char *line;

  // check if fd is negative, if BUFFER_SIZE is negative, or we don't have
  // permissions to read the file
  line = NULL;
  if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
    return (NULL);
  read_and_store(&store, fd);
  line = get_line(&store);
  return (line);
}

// int main(void) {
//   int fd;
//   char *line;
//   fd = open("./test.txt", O_RDONLY);

//   while (1) {
//     line = get_next_line(fd);
//     if (!line) {
//       break;
//     }
//     printf("%s", line);
//   }
//   free(line);
//   return (0);
// }