/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:31:48 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:39:21 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	left_str = ft_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_find_line(left_str);
	left_str = ft_new_str(left_str);
	return (line);
}

char	*ft_left_str(int fd, char *left_str)
{
	char	*buff;
	int		i;

	i = 1;
	buff = ft_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(left_str, '\n') && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			return (NULL);
		}
		buff[i] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	return (left_str);
}
