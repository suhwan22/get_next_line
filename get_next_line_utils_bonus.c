/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:50:33 by suhkim            #+#    #+#             */
/*   Updated: 2022/06/22 18:52:09 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (s1);
	s1_len = 0;
	while (s1 && *(s1 + s1_len))
		s1_len++;
	s2_len = 0;
	while (*(s2 + s2_len))
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	if (s1)
		ft_strlcpy(str, (char *)s1, s1_len + 1);
	ft_strlcpy(str + s1_len, (char *)s2, s2_len + 1);
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*sptr;
	size_t		len;

	if (!s)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	sptr = s;
	if (c == 0)
		return ((char *)sptr + len);
	while (*sptr)
	{
		if (*(char *)sptr == (char)c)
			return ((char *)sptr);
		sptr++;
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	while (*(dst + d_len))
		d_len++;
	s_len = 0;
	while (*(src + s_len))
		s_len++;
	i = 0;
	if (d_len >= dstsize)
		return (s_len + dstsize);
	while (*(src + i) != '\0' && d_len + i < dstsize - 1)
	{
		*(dst + d_len + i) = *(src + i);
		i++;
	}
	*(dst + d_len + i) = '\0';
	return (s_len + d_len);
}

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (*(src + len))
		len++;
	i = 0;
	if (dstsize == 0)
		return ;
	while (*(src + i) != '\0')
	{
		if (i == dstsize - 1)
			break ;
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
}

void	lst_del(t_list	*head)
{
	t_list	*temp;
	t_list	*node;

	node = head->next;
	while (node)
	{
		free(node->str);
		temp = node;
		node = node->next;
		free(temp);
	}
}
