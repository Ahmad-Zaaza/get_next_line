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
t_list *ft_lstfirst(t_list *lst) {

  t_list *current;

  if (!lst)
    return (NULL);
  current = lst;
  while (current->prev) {
    current = current->prev;
  }
  return (current);
}

void lstclear_prev(t_list *node) {
  t_list *current;
  t_list *tmp;

  current = node->prev;
  while (current) {
    tmp = current->prev;
    free(current->content);
    free(current);
    current = tmp;
  }
}

t_list *ft_lstnew(char *content) {
  t_list *lst;

  lst = (t_list *)malloc(sizeof(t_list));
  if (!lst)
    return (NULL);
  lst->content = content;
  lst->next = NULL;
  lst->prev = NULL;
  return (lst);
}

void ft_lstadd_back(t_list **store, t_list *lst) {

  t_list *last;

  if (!*store) {
    *store = lst;
  } else {
    last = ft_lstlast(*store);
    lst->prev = last;
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

int ft_strlen(const char *str) {
  int i;

  i = 0;
  while (str[i]) {
    i++;
  }
  return (i);
}

char *ft_strjoin(char const *s1, char const *s2) {
  int s1_len;
  int s2_len;
  char *str;
  int i;
  int j;

  if (!s1 || !s2)
    return (NULL);
  s1_len = ft_strlen(s1);
  s2_len = ft_strlen(s2);
  str = (char *)malloc(s1_len + s2_len + 1);
  if (!str)
    return (NULL);
  i = 0;
  j = 0;
  while (s1[i])
    str[j++] = s1[i++];
  i = 0;
  while (s2[i])
    str[j++] = s2[i++];
  str[j] = '\0';
  return (str);
}

size_t ft_strlcat(char *dest, char *src, size_t dest_size) {
  size_t i;
  size_t dest_len;

  if (dest_size == 0)
    return (ft_strlen(src));
  dest_len = ft_strlen(dest);
  if (dest_size <= dest_len)
    return (ft_strlen(src) + dest_size);
  i = 0;
  while (src[i] && dest_len < (dest_size - 1)) {
    dest[dest_len++] = src[i++];
  }
  dest[dest_len] = '\0';
  return (dest_len + ft_strlen(&src[i]));
}

size_t ft_strncat(char *dest, char *src, size_t n)
{
  size_t i;
  size_t dest_len;

  dest_len = ft_strlen(dest);
  i = 0;
  while (src[i] && i < n)
    dest[dest_len++] = src[i++];
  dest[dest_len] = '\0';
  return (dest_len);
}
