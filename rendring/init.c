/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:01:34 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/17 16:07:49 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

void	init_images(t_mlx *all)
{
	all->buffer.door.img = mlx_new_image(all->connection, 32, 32);
	all->buffer.wall.img = mlx_new_image(all->connection, 32, 32);
	all->buffer.player.img = mlx_new_image(all->connection, 32, 32);
	all->buffer.fov.img = mlx_new_image(all->connection, 16, 16);
}

void	get_adresses(t_mlx *all)
{
	all->buffer.door.addr.addr = mlx_get_data_addr(all->buffer.door.img,
			&all->buffer.door.addr.bpp, &all->buffer.door.addr.size_len,
			&all->buffer.door.addr.endian);
	all->buffer.wall.addr.addr = mlx_get_data_addr(all->buffer.wall.img,
			&all->buffer.wall.addr.bpp, &all->buffer.wall.addr.size_len,
			&all->buffer.wall.addr.endian);
	all->buffer.player.addr.addr = mlx_get_data_addr(all->buffer.player.img,
			&all->buffer.player.addr.bpp, &all->buffer.player.addr.size_len,
			&all->buffer.player.addr.endian);
	all->buffer.fov.addr.addr = mlx_get_data_addr(all->buffer.fov.img,
			&all->buffer.fov.addr.bpp, &all->buffer.fov.addr.size_len,
			&all->buffer.fov.addr.endian);
}

void	fill_wall_door(t_mlx *all)
{
	int				byte_pp;
	unsigned int	offset;
	int				i;
	int				j;

	byte_pp = all->buffer.wall.addr.bpp / 8;
	i = 0;
	while (i < WALL_TILE)
	{
		j = 0;
		while (j < WALL_TILE)
		{
			if (i == 0 || i == WALL_TILE - 1 || j == 0 || j == WALL_TILE - 1)
			{
				offset = i * all->buffer.wall.addr.size_len + j * byte_pp;
				*(unsigned int *)(all->buffer.wall.addr.addr + offset) = GREY;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < DOOR_TILE)
	{
		j = 0;
		while (j < DOOR_TILE)
		{
			if (i == 0 || i == DOOR_TILE - 1 || j == 0 || j == DOOR_TILE - 1)
			{
				offset = i * all->buffer.door.addr.size_len + j * byte_pp;
				*(unsigned int *)(all->buffer.door.addr.addr + offset) = GREEN;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			if (i == 0 || i == 32 - 1 || j == 0 || j == 32 - 1)
			{
				offset = i * all->buffer.player.addr.size_len + j * byte_pp;
				*(unsigned int *)(all->buffer.player.addr.addr + offset) = RED;
			}
			j++;
		}
		i++;
	}
}