/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:54:46 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/04 08:30:53 by yael-yas         ###   ########.fr       */
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
	all->map->textures->door = ft_strdup("maps/door.xpm");
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

void	draw_walls(t_mlx *all)
{
	mlx_put_image_to_window(all->connection, all->window,
		all->buffer.screen->img, 0, 0);
}

int	handle_space_key(t_mlx *all)
{
	double	targetx;
	double	targety;
	int		mapx;
	int		mapy;

	targetx = all->map->player_x + cos(all->map->angle);
	targety = all->map->player_y - sin(all->map->angle);
	mapx = (int)targetx;
	mapy = (int)targety;
	if (mapx >= 0 && mapx < WIN_WIDTH && mapy >= 0 && mapy < WIN_HEIGHT)
	{
		if (all->map->map[mapy][mapx] == 'D')
			all->map->map[mapy][mapx] = 'O';
		else if (all->map->map[mapy][mapx] == 'O')
			all->map->map[mapy][mapx] = 'D';
	}
	return (0);
}
