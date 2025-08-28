/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:54:46 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/28 15:24:55 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

void	get_angle(t_map *units, char direction)
{
	if (direction == 'N')
		units->angle = M_PI / 2;
	else if (direction == 'E')
		units->angle = 0;
	else if (direction == 'W')
		units->angle = M_PI;
	else if (direction == 'S')
		units->angle = 3 * M_PI / 2;
}

void	get_player_position(t_map *units)
{
	int	i;
	int	j;

	i = 0;
	while (units->map[i])
	{
		j = 0;
		while (units->map[i][j])
		{
			if (units->map[i][j] == 'N' || units->map[i][j] == 'E'
				|| units->map[i][j] == 'W' || units->map[i][j] == 'S')
			{
				units->player_x = (float)j + 0.5;
				units->player_y = (float)i + 0.5;
				get_angle(units, units->map[i][j]);
				units->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	load_door_texture(t_mlx *all, int *width, int *height)
{
	all->map->textures->door = strdup("maps/door.xpm");
	all->buffer.door.img = mlx_xpm_file_to_image(all->connection,
			all->map->textures->door, width, height);
	if (!all->buffer.door.img)
	{
		perror("Failed to load door texture");
		exit(1);
	}
	all->buffer.door.addr.addr = mlx_get_data_addr(all->buffer.door.img,
			&all->buffer.door.addr.bpp, &all->buffer.door.addr.size_len,
			&all->buffer.door.addr.endian);
}
