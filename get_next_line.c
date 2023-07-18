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

#include "fcntl.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"


char *get_next_line(int fd) {}

int main(void) {

  char buffer[BUFFER_SIZE];
  int bytes_read;
  char *newline;
  int fd = open("./test.txt", O_RDONLY);

  while ((bytes_read = read(fd, buffer, BUFFER_SIZE))) {
    buffer[bytes_read] = '\0';
    newline = strchr(buffer, '\n');
    if (newline) {
      //   *newline = '\0';
    }
    printf("%s\t", buffer);
  }

  return (0);
}