/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:40:03 by suhkim            #+#    #+#             */
/*   Updated: 2022/06/22 19:00:53 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#	define	GET_NEXT_LINE_H

#	include <unistd.h>
#	include <stdlib.h>

typedef struct	s_gnl_list
{
	struct	s_gnl_list	*next;
	struct	s_gnl_list	*pre;
	char	*str;
	int		fd;
}	t_list;

char	*get_next_line(int	fd);
t_list	*add_front(t_list *head, int fd);
t_list	*check_fd(t_list *head, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*get_one_line(t_list *node);
void	lst_del(t_list *head);
char	*read_fd(t_list *node);

#endif
