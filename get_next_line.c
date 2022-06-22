/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:38:11 by suhkim            #+#    #+#             */
/*   Updated: 2022/06/22 18:53:42 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

t_list	*add_front(t_list *head, int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->fd = fd;
	new->next = head->next;
	new->pre = head;
	new->str = 0;
	head->next = new;
	return (new);
}

t_list	*check_fd(t_list *head, int fd)
{
	t_list	*temp;

	temp = head->next;
	while (temp)
	{
		if (fd == temp->fd)
		{
			return (temp);
		}
		temp = temp->next;
	}
	return (add_front(head, fd));
}

char	*read_fd(t_list *node)
{
	char	*buf;
	int		size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	size = 1;
	while (size > 0 && !ft_strchr(node->str, '\n'))
	{
		size = read(node->fd, buf, BUFFER_SIZE);
		if (size == -1)
			break ;
		*(buf + size) = 0;
		node->str = ft_strjoin(node->str, buf);
		if (!node->str)
			break ;
	}
	free(buf);
	if (size == -1)
		return (0);
	return (node->str);
}

char	*get_one_line(t_list *node)
{
	char	*ans;
	char	*temp;
	size_t	len;
	size_t	end;

	len = 0;
	while (*(node->str + len) && *(node->str + len) != '\n')
		len++;
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (0);
	ft_strlcpy(ans, node->str, len + 1);
	end = 0;
	while (*(node->str + end))
		end++;
	if (end - len)
	{
		temp = (char *)malloc(sizeof(char) * (end - len));
		if (!temp)
			return (0);
		ft_strlcpy(temp, node->str + len + 1, end - len);
		free(node->str);
		node->str = temp;
	}
	return (ans);
}

char	*get_next_line(int fd)
{
	static t_list	head;
	t_list			*node;
	char			*ans;

	node = check_fd(&head, fd);
	if (!node)
	{
		lst_del(&head);
		return (0);
	}
	if (!read_fd(node))
	{
		lst_del(&head);
		return (0);
	}
	ans = get_one_line(node);
	return (ans);
}
