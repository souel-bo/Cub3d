/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/06/27 08:52:23 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

bool	check_line(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (true);
	else if (!ft_strncmp(line, "SO", 2))
		return (true);
	else if (!ft_strncmp(line, "WE", 2))
		return (true);
	else if (!ft_strncmp(line, "EA", 2))
		return (true);
	return (false);
}

t_textures *store_path(t_map *data, char *line, t_textures *textures)
{
	
	if (!ft_strncmp(line, "NO", 2))
		textures->north_path = ft_strdup(&line[3]);
	else if (!ft_strncmp(line, "SO", 2))
		textures->south_path = ft_strdup(&line[3]);
	else if (!ft_strncmp(line, "WE", 2))
		textures->west_path = ft_strdup(&line[3]);
	else if (!ft_strncmp(line, "EA", 2))
		textures->east_path = ft_strdup(&line[3]);
	return textures;
}

t_map	*parse_map(char *map_file)
{
	int		fd;
	t_map	*data;
	char	*line;

	fd = open(map_file, O_RDONLY);
	data = malloc(sizeof(t_map));
	data->textures = malloc(sizeof(t_textures));
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (check_line(line))
			data->textures = store_path(data, line, data->textures);
		free(line);
	}
	return (data);
}

int	main(int ac, char **av)
{
	t_map *data;
	if (ac != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	data = parse_map(av[1]);
}