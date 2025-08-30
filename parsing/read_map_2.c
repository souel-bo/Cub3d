/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:57:19 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/30 18:57:57 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	skip_empty_lines(int fd, char **line)
{
	*line = get_next_line(fd);
	while (*line != NULL)
	{
		if (**line != '\n')
			break ;
		free(*line);
		*line = get_next_line(fd);
	}
}

char	**read_file(int fd)
{
	char	*line;
	int		i;
	char	**array;

	i = 0;
	array = malloc(sizeof(char *) * 1000);
	skip_empty_lines(fd, &line);
	while (line != NULL)
	{
		if (!*line || *line == '\n')
		{
			free(line);
			break ;
		}
		else
			array[i++] = line;
		line = get_next_line(fd);
	}
	array[i] = NULL;
	return (array);
}
