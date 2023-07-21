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

char	*get_next_line(int fd)
{
	static t_list	*store;
	t_list			*newline_node;
	int				node_index;
	char			*line;

	// check if fd is negative, if BUFFER_SIZE is negative, or we don't have
	// permissions to read the file
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	node_index = 0;
	line = NULL;
	// 1. Read from fd until the buffer size and store.
	read_and_store(&store, fd);
	line = get_line(&store);
	//   ft_print_lst(&store);
	return (line);
}

char	*get_line(t_list **store, int count)
{
	t_list	*current;
	char	*line;
	int		node_count;

	line = (char *)malloc(sizeof(char) * count + 1);
	if (!line)
		return (NULL);
	current = *store;
	while (node_count <= count)
	{
		line[i] = 
		node_count++;
		current = current->next;
	}
	return (line);
}

void	read_and_store(t_list **store, int fd)
{
	char	*buffer;
	int		readed;
	int		i;
	char	*line;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while ((readed = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[readed] = '\0';
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				line = get_line(store, i)
			}
			else
				ft_lstadd_back(store, ft_lstnew(&buffer[i]));
			i++;
		}
	}
}

t_list	*find_newline_node(t_list **store, int *node_index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *store;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == '\n')
				return (tmp);
			i++;
		}
		*node_index += 1;
		tmp = tmp->next;
	}
	return (NULL);
}

int	main(void)
{
	int fd;
	char *line;
	fd = open("./test.txt", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		printf("%s\n", line);
	}
	free(line);
	return (0);
}