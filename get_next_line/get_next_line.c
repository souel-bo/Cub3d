/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:31:48 by yael-yas          #+#    #+#             */
/*   Updated: 2024/11/18 21:25:16 by yael-yas         ###   ########.fr       */
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
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(left_str, '\n') && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("test/texts.txt", O_RDONLY);
	i = 1;
	while (i < 13)
	{
		line = get_next_line(-1);
		printf("line [%d] : %s", i, line);
		free(line);
		i++;
	}
	//printf("line [%d] : %s\n", i, line);
	//free(line);
	close(fd1);
	return (0);
	
}
*/
