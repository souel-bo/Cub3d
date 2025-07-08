/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/08 16:11:05 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

void	allocation(t_mlx *all)
{
	all->buffer = malloc(sizeof(t_images));
	all->buffer->addr = malloc(sizeof(t_addr));
}

void	fill_image(t_mlx *all, int collor, int size)
{
	int	offset;
	int	bpp_bytes;

	int i, j;
	bpp_bytes = all->buffer->addr->bpp / 8;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
			{
				offset = i * all->buffer->addr->size_len + j * bpp_bytes;
				*(unsigned int *)(all->buffer->addr->addr + offset) = collor;
			}
			j++;
		}
		i++;
	}
}

void	draw_player_image(t_mlx *all, char dir)
{
	int	bpp_bytes;
	int	rect_size;
	int	end_x;
	int	end_y;
	int	cx;
	int	cy;
	int	px;
	int	py;
	int	offset;

	bpp_bytes = all->buffer->addr->bpp / 8;
	rect_size = 15;
	int start_x, start_y;
	if (dir == 'N')
	{
		start_x = 8;
		start_y = 17;
	}
	else if (dir == 'S')
	{
		start_x = 8;
		start_y = 0;
	}
	else if (dir == 'E')
	{
		start_x = 0;
		start_y = 8;
	}
	else if (dir == 'W')
	{
		start_x = 17;
		start_y = 8;
	}
	end_x = start_x + rect_size;
	end_y = start_y + rect_size;
	for (int y = start_y; y < end_y; y++)
	{
		for (int x = start_x; x < end_x; x++)
		{
			offset = y * all->buffer->addr->size_len + x * bpp_bytes;
			*(unsigned int *)(all->buffer->addr->addr + offset) = 0xFF0000;
		}
	}
	cx = start_x + rect_size / 2;
	cy = start_y + rect_size / 2;
	for (int i = 1; i < 32; i++)
	{
		px = cx;
		py = cy;
		if (dir == 'N')
			py = cy - i;
		else if (dir == 'S')
			py = cy + i;
		else if (dir == 'E')
			px = cx + i;
		else if (dir == 'W')
			px = cx - i;
		if (px < 0 || px >= 32 || py < 0 || py >= 32)
			break ;
		offset = py * all->buffer->addr->size_len + px * bpp_bytes;
		*(unsigned int *)(all->buffer->addr->addr + offset) = 0xFFFF00;
	}
}

void	set_walls(t_mlx *all)
{
	all->buffer->wall = mlx_new_image(all->connection, 32, 32);
	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->wall,
			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
			&all->buffer->addr->endien);
	fill_image(all, 0x808080, WALL_TILE);
}

void	set_player(t_mlx *all, char dir)
{
	all->buffer->player = mlx_new_image(all->connection, 32, 32);
	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->player,
			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
			&all->buffer->addr->endien);
	draw_player_image(all, dir);
}

void	set_door(t_mlx *all)
{
	all->buffer->door = mlx_new_image(all->connection, 32, 32);
	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->door,
			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
			&all->buffer->addr->endien);
	fill_image(all, 0x006400, DOOR_TILE);
}

void	set_images(t_mlx *all, char dir)
{
	set_walls(all);
	set_player(all, dir);
	set_door(all);
}

char get_direction(t_mlx *all)
{
	int i = 0;
	int j = 0;
	while (all->map->map[i])
	{
		j = 0;
		while (all->map->map[i][j])
		{
			if (all->map->map[i][j] == 'N' || all->map->map[i][j] == 'S'
				|| all->map->map[i][j] == 'W' || all->map->map[i][j] == 'E')
					return (all->map->map[i][j]);		
			j++;
		}
		i++;
	}
	return '\0';
}

void	draw_map(t_mlx *all)
{
	int i, j;
	i = 0, j = 0;
	allocation(all);
	char dir = get_direction(all);
	set_images(all, dir);
	while (all->map->map[i])
	{
		j = 0;
		while (all->map->map[i][j])
		{
			if (all->map->map[i][j] == '1')
				mlx_put_image_to_window(all->connection, all->window,
					all->buffer->wall, j * 32, i * 32);
			else if (all->map->map[i][j] == 'N' || all->map->map[i][j] == 'S'
				|| all->map->map[i][j] == 'W' || all->map->map[i][j] == 'E')
				mlx_put_image_to_window(all->connection, all->window,
					all->buffer->player, j * 32, i * 32);
			else if (all->map->map[i][j] == 'D')
				mlx_put_image_to_window(all->connection, all->window,
					all->buffer->door, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map units;
	t_mlx all;
	int i;
	i = 0;
	if (start_parsing(&units, argv))
		return (printf("map not valid\n"), 0);
	while (units.map[i])
	{
		printf("%s", units.map[i]);
		i++;
	}
	all.connection = mlx_init();
	all.map = &units;
	all.window = mlx_new_window(all.connection, 1100, 600, "Cub3D");
	draw_map(&all);
	mlx_loop(all.connection);
}