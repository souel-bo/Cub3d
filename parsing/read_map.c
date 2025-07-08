/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:26:57 by yael-yas          #+#    #+#             */
/*   Updated: 2025/07/08 18:25:23 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	**read_file(int fd)
{
	char	*line;
	int		i;
	char	**array;

	i = 0;
	array = malloc(sizeof(char *) * 100);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (*line != '\n')
			break ;
	}
	while (line != NULL)
	{
		if (!*line || *line == '\n')
			break ;
		else
		{
			array[i] = line;
			i++;
		}
		line = get_next_line(fd);
	}
	array[i] = NULL;
	return (array);
}

int	start_parsing(t_map *units, char **argv)
{
	int				fd;
	int				i;
	t_parse_file	*collec;

	(void)units;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	collec = malloc(sizeof(t_parse_file));
	collec->step_one = read_file(fd);
	collec->step_two = read_file(fd);
	collec->step_three = read_file(fd);
	collec->step_four = read_file(fd);
	close(fd);
	if (*collec->step_four)
		return (printf("param 4\n") ,1);
	if (check_textures(collec->step_one, units))
		return (printf("textures\n") ,1);
	if (ft_colors(collec->step_two, units))
		return (printf("colors\n") ,1);
	units->map = collec->step_three;
	if (make_map_cube(units))
			return (printf("map\n") ,-1);
	return (0);
}
