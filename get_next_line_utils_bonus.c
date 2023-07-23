#include "get_next_line_bonus.h"

void	init_queue(t_queue *queue)
{
	queue->first = NULL;
	queue->last = NULL;
}

int	hash_code(int key)
{
	return (key % MAX_FD);
}

int	has_newline(t_queue *queue)
{
	t_list	*tmp;
	int		i;

	tmp = queue->first;
	while (tmp)
	{
		i = 0;
		if (tmp->content == '\n')
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

char	*get_line(t_queue *queue)
{
	int		count;
	char	*str;
	t_list	*tmp;

	tmp = queue->first;
	count = 0;
	while (tmp && tmp->content != '\n')
	{
		count++;
		tmp = tmp->next;
	}
	str = (char *)malloc(sizeof(char) * count + 2);
	if (!str)
		return (NULL);
	count = 0;
	while (queue->first && queue->first->content != '\n')
		str[count++] = unshift_queue(queue);
	str[count++] = unshift_queue(queue);
	str[count] = '\0';
	return (str);
}

char	*get_rest(t_queue *queue)
{
	t_list	*tmp;
	char	*line;
	int		count;

	tmp = queue->first;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	line = (char *)malloc(count + 1);
	count = 0;
	while (queue->first)
	{
		line[count++] = unshift_queue(queue);
	}
	line[count] = '\0';
	return (line);
}

char	unshift_queue(t_queue *queue)
{
	t_list	*tmp;
	char	c;

	c = queue->first->content;
	tmp = queue->first;
	queue->first = queue->first->next;
	free(tmp);
	return (c);
}

void	push_queue(t_queue *queue, char content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return ;
	if (!queue->first)
	{
		queue->first = new;
		queue->last = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
}

t_list	*ft_lstnew(char content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

int	queue_empty(t_queue *queue)
{
	return (!queue->first);
}