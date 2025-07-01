/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/06/30 11:25:50 by souel-bo         ###   ########.fr       */
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

bool check_collor(char *line)
{
	if (line[0] == 'F')
		return true;
	else if (line[0] == 'C')
		return true;
	return false;
}

t_map *parse_color(t_map *data, char *line)
{
	char **splited;
	if (line[0] == 'F')
	{
		splited = ft_split(&line[2], ',');
		data->floor_collors = malloc(sizeof(t_flor_collors));
		data->floor_collors->red = ft_atoi(splited[0]);
		data->floor_collors->green = ft_atoi(splited[1]);
		data->floor_collors->blue = ft_atoi(splited[2]);
	}
	else if (line[0] == 'C')
	{
		splited = ft_split(&line[2], ',');
		data->ceilling_collors = malloc(sizeof(t_ceilling_collors));
		data->ceilling_collors->red = ft_atoi(splited[0]);
		data->ceilling_collors->green = ft_atoi(splited[1]);
		data->ceilling_collors->blue = ft_atoi(splited[2]);
	}
	return data;
}

t_map	*parse_map(char *map_file)
{
	int		fd;
	t_map	*data;
	char	*line;
	int i = 0;

	fd = open(map_file, O_RDONLY);
	data = malloc(sizeof(t_map));
	data->textures = malloc(sizeof(t_textures));
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (check_line(line))
			data->textures = store_path(data, line, data->textures);
		else if (check_collor(line))
			data = parse_color(data, line);
		else
			i++;
		free(line);
	}
	return (data);
}

void print(t_map *data)
{
	printf("%s", data->textures->north_path);
	printf("%s", data->textures->south_path);
	printf("%s", data->textures->west_path);
	printf("%s", data->textures->east_path);
	printf("%d ", data->floor_collors->red);
	printf("%d ", data->floor_collors->green);
	printf("%d \n", data->floor_collors->blue);
	printf("%d ", data->ceilling_collors->red);
	printf("%d ", data->ceilling_collors->green);
	printf("%d \n", data->ceilling_collors->blue);

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
	print(data);
}