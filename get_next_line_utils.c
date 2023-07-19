#include "get_next_line.h"

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

void add_to_store(t_list **store, char *content) {
  char *str;
  int i;

  str = ft_strdup(content);
  if (!str)
    return;

  ft_lstadd_back(store, ft_lstnew(str));
}

void ft_print_lst(t_list **store) {
  t_list *tmp;

  tmp = *store;
  while (tmp) {
    printf("%s\n", tmp->content);
    tmp = tmp->next;
  }
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
  return str;
}

int ft_strlen(char *str) {
  int i;

  i = 0;
  while (str[i]) {
    i++;
  }
  return (i);
}