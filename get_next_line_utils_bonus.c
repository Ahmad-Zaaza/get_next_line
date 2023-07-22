#include "get_next_line_bonus.h"
#include <strings.h>

t_list *ft_lstlast(t_list *lst) {
  t_list *current;

  if (!lst)
    return (NULL);
  current = lst;
  while (current->next) {
    current = current->next;
  }
  return (current);
}

t_list *ft_lstnew(char *content) {
  t_list *lst;

  lst = (t_list *)malloc(sizeof(t_list));
  if (!lst)
    return (NULL);
  lst->content = content;
  lst->next = NULL;
  return (lst);
}

void ft_lstadd_back(t_list **store, t_list *lst) {
  t_list *last;

  if (!*store) {
    *store = lst;
  } else {
    last = ft_lstlast(*store);
    last->next = lst;
  }
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

  line = (char *)malloc(sizeof(char) * node_index + 1);
  if (!line)
    return (NULL);
  i = 0;
  bzero(line, node_index + 1);
  while (*store && i < node_index) {

    line[i] = (*store)->content[0];
    tmp = (*store)->next;
    free((*store)->content);
    free((*store));
    *store = tmp;
    i++;
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
  free(buffer);
}

char *ft_strdup(char *content) {
  char *str;
  int i;
  int len;

  len = ft_strlen(content);
  str = (char *)malloc(sizeof(char) * len + 1);
  if (!str)
    return (NULL);
  i = 0;
  while (content[i]) {
    str[i] = content[i];
    i++;
  }
  str[i] = '\0';
  return (str);
}

int ft_strlen(const char *str) {
  int i;

  i = 0;
  while (str[i]) {
    i++;
  }
  return (i);
}
