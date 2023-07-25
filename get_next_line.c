/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:46:35 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/25 10:54:09 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_queue(t_queue *queue)
{
	queue->first = NULL;
	queue->last = NULL;
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

char	*get_next_line(int fd)
{
	static t_queue	queue;
	static int		is_init;
	char			*buffer;
	int				readed;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!is_init)
	{
		init_queue(&queue);
		is_init = 1;
	}
	if (has_newline(&queue))
		return (get_line(&queue));
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = read(fd, buffer, BUFFER_SIZE);
	buffer[readed] = '\0';
	return (handle_read(fd, readed, buffer, &queue));
}

char	*handle_read(int fd, int readed, char *buffer, t_queue *queue)
{
	int	i;

	if (readed > 0)
	{
		i = 0;
		while (buffer[i])
		{
			push_queue(queue, buffer[i]);
			i++;
		}
		free(buffer);
		return (get_next_line(fd));
	}
	else
	{
		free(buffer);
		if (!queue->first)
			return (NULL);
		else
			return (get_rest(queue));
	}
}
