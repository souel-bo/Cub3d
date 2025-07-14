/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/14 14:48:40 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

// void	fill_image(t_mlx *all, int collor, int size)
// {
// 	int	offset;
// 	int	bpp_bytes;

// 	int i, j;
// 	bpp_bytes = all->buffer->addr->bpp / 8;
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
// 			{
// 				offset = i * all->buffer->addr->size_len + j * bpp_bytes;
// 				*(unsigned int *)(all->buffer->addr->addr + offset) = collor;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_player_image(t_mlx *all, char dir)
// {
// 	int	bpp_bytes;
// 	int	rect_size;
// 	int	end_x;
// 	int	end_y;
// 	int	cx;
// 	int	cy;
// 	int	px;
// 	int	py;
// 	int	offset;

// 	bpp_bytes = all->buffer->addr->bpp / 8;
// 	rect_size = 15;
// 	int start_x, start_y;
// 	start_x = 9;
// 	start_y = 9;
// 	end_x = start_x + rect_size;
// 	end_y = start_y + rect_size;
// 	for (int y = start_y; y < end_y; y++)
// 	{
// 		for (int x = start_x; x < end_x; x++)
// 		{
// 			offset = y * all->buffer->addr->size_len + x * bpp_bytes;
// 			*(unsigned int *)(all->buffer->addr->addr + offset) = 0xFF0000;
// 		}
// 	}
// 	cx = start_x + rect_size / 2;
// 	cy = start_y + rect_size / 2;
// 	for (int i = 1; i < 32; i++)
// 	{
// 		px = cx;
// 		py = cy;
// 		if (dir == 'N')
// 			py = cy - i;
// 		else if (dir == 'S')
// 			py = cy + i;
// 		else if (dir == 'E')
// 			px = cx + i;
// 		else if (dir == 'W')
// 			px = cx - i;
// 		if (px < 0 || px >= 32 || py < 0 || py >= 32)
// 			break ;
// 		offset = py * all->buffer->addr->size_len + px * bpp_bytes;
// 		*(unsigned int *)(all->buffer->addr->addr + offset) = 0xFFFF00;
// 	}
// }

// void	set_walls(t_mlx *all)
// {
// 	all->buffer->wall = mlx_new_image(all->connection, 32, 32);
// 	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->wall,
// 			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
// 			&all->buffer->addr->endien);
// 	fill_image(all, 0x808080, WALL_TILE);
// }

// void	set_player(t_mlx *all, char dir)
// {
// 	all->buffer->player = mlx_new_image(all->connection, 32, 32);
// 	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->player,
// 			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
// 			&all->buffer->addr->endien);
// 	draw_player_image(all, dir);
// }

// void	set_door(t_mlx *all)
// {
// 	all->buffer->door = mlx_new_image(all->connection, 32, 32);
// 	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->door,
// 			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
// 			&all->buffer->addr->endien);
// 	fill_image(all, 0x006400, DOOR_TILE);
// }

// void set_fov(t_mlx *all)
// {
// 	all->buffer->fov = mlx_new_image(all->connection, 32, 32);
// 	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->fov,
// 			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
// 			&all->buffer->addr->endien);
// 	// fill_fov(all, );
// }

// void	set_images(t_mlx *all, char dir)
// {
// 	set_walls(all);
// 	set_player(all, dir);
// 	set_door(all);
// 	set_fov(all);
// }

// char get_direction(t_mlx *all)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (all->map->map[i])
// 	{
// 		j = 0;
// 		while (all->map->map[i][j])
// 		{
// 			if (all->map->map[i][j] == 'N' || all->map->map[i][j] == 'S'
// 				|| all->map->map[i][j] == 'W' || all->map->map[i][j] == 'E')
// 					return (all->map->map[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return ('\0');
// }

// void	draw_map(t_mlx *all)
// {
// 	int i, j;
// 	i = 0, j = 0;
// 	allocation(all);
// 	char dir = get_direction(all);
// 	set_images(all, dir);
// 	while (all->map->map[i])
// 	{
// 		j = 0;
// 		while (all->map->map[i][j])
// 		{
// 			if (all->map->map[i][j] == '1')
// 				mlx_put_image_to_window(all->connection, all->window,
// 					all->buffer->wall, j * 32, i * 32);
// 			else if (all->map->map[i][j] == 'N' || all->map->map[i][j] == 'S'
// 				|| all->map->map[i][j] == 'W' || all->map->map[i][j] == 'E')
// 				mlx_put_image_to_window(all->connection, all->window,
// 					all->buffer->player, j * 32, i * 32);
// 			else if (all->map->map[i][j] == 'D')
// 				mlx_put_image_to_window(all->connection, all->window,
// 					all->buffer->door, j * 32, i * 32);
// 			j++;
// 		}
// 		i++;
// 	}
// }

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

void fill_wall_door(t_mlx *all)
{
	int byte_pp;
	unsigned int offset;
	byte_pp = all->buffer.wall.addr.bpp / 8;

	int i = 0;
	int j;

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

void draw_player(t_mlx *all)
{
	mlx_put_image_to_window(all->connection, all->window,
		all->buffer.player.img, (int)(all->map->player_x * 32 -16), (int)(all->map->player_y *32 -16));
}
void draw_map(t_mlx *all)
{
	int i;
	int j;
	i = 0;
	while (all->map->map[i])
	{
		j = 0;
		while (all->map->map[i][j])
		{
			if (all->map->map[i][j] == '1')
				mlx_put_image_to_window(all->connection, all->window, all->buffer.wall.img, j * 32, i *32);
			else if (all->map->map[i][j] == 'D')
				mlx_put_image_to_window(all->connection, all->window, all->buffer.door.img, j * 32, i *32);
			j++;
		}
		i++;
	}
	draw_player(all);
}


int key_hook(int key, t_mlx *all)
{
	float next_x = all->map->player_x;
	float next_y = all->map->player_y;
	float speed = 0.10;

	float px = all->map->player_x;
	float py = all->map->player_y;
	if (key == RIGHT)
	{
		next_x += speed;
		if (
			all->map->map[(int)(py - 0.49)][(int)(next_x + 0.49)] != '1' &&
			all->map->map[(int)(py + 0.49)][(int)(next_x + 0.49)] != '1'
		)
			all->map->player_x = next_x;
	}
	else if (key == LEFT)
	{
		next_x -= speed;
		if (
			all->map->map[(int)(py - 0.49)][(int)(next_x - 0.49)] != '1' &&
			all->map->map[(int)(py + 0.49)][(int)(next_x - 0.49)] != '1'
		)
			all->map->player_x = next_x;
	}
	else if (key == UP)
	{
		next_y -= speed;
		if (
			all->map->map[(int)(next_y - 0.49)][(int)(px - 0.49)] != '1' &&
			all->map->map[(int)(next_y - 0.49)][(int)(px + 0.49)] != '1'
		)
			all->map->player_y = next_y;
	}
	else if (key == DOWN)
	{
		next_y += speed;
		if (
			all->map->map[(int)(next_y + 0.49)][(int)(px - 0.49)] != '1' &&
			all->map->map[(int)(next_y + 0.49)][(int)(px + 0.49)] != '1'
		)
			all->map->player_y = next_y;
	}
	else if (key == ESCAPE)
		exit(0);
	mlx_clear_window(all->connection, all->window);
	draw_map(all);
	return 0;
}


void get_player_position(t_map *units)
{
	int i = 0, j;
	while (units->map[i])
	{
		j = 0;
		while (units->map[i][j])
		{
			if (units->map[i][j] == 'N' || units->map[i][j] == 'E' || units->map[i][j] == 'W' || units->map[i][j] == 'S')
			{
				units->player_x = (float)j + 0.5;
				units->player_y = (float)i + 0.5;
				units->map[i][j] = '0';
			}
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
	units.player_x = 0;
	units.player_y = 0;
	if (start_parsing(&units, argv))
		return (printf("map not valid\n"), 1);
	get_player_position(&units);
	while (units.map[i])
	{
		printf("%s", units.map[i]);
		i++;
	}
	all.connection = mlx_init();
	all.map = &units;
	all.window = mlx_new_window(all.connection, 1100, 600, "Cub3D");
	// draw_map(&all);
	init_images(&all);
	get_adresses(&all);
	fill_wall_door(&all);
	draw_map(&all);
	mlx_hook(all.window, 2, 1L<<0, key_hook, &all);
	mlx_loop(all.connection);
	// printf("%f", M_PI);
}