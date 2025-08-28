/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/24 16:14:04 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

void	draw_walls(t_mlx *all)
{
	mlx_put_image_to_window(all->connection, all->window,
		all->buffer.screen->img, 0, 0);
}
int	handle_space_key(t_mlx *all)
{
	double	targetX;
	double	targetY;
	int		mapX;
	int		mapY;

	targetX = all->map->player_x + cos(all->map->angle);
	targetY = all->map->player_y - sin(all->map->angle);
	mapX = (int)targetX;
	mapY = (int)targetY;
	if (mapX >= 0 && mapX < WIN_WIDTH && mapY >= 0 && mapY < WIN_HEIGHT)
	{
		if (all->map->map[mapY][mapX] == 'D')
			all->map->map[mapY][mapX] = 'O';
		else if (all->map->map[mapY][mapX] == 'O')
			all->map->map[mapY][mapX] = 'D';
	}
	return (0);
}

void	free_exit(t_mlx *all)
{
	int	height;
	int	i;

	height = 0;
	while (all->map->map[height])
		height++;
	i = 0;
	while (i < height)
	{
		free(all->map->map[i]);
		i++;
	}
	mlx_destroy_image(all->connection, all->buffer.door.img);
	mlx_destroy_image(all->connection, all->buffer.north.img);
	mlx_destroy_image(all->connection, all->buffer.screen->img);
	mlx_destroy_image(all->connection, all->buffer.south.img);
	mlx_destroy_image(all->connection, all->buffer.east.img);
	mlx_destroy_image(all->connection, all->buffer.west.img);
	mlx_destroy_window(all->connection, all->window);
	mlx_destroy_display(all->connection);
	free(all->map->ceilling_collors);
	free(all->map->floor_collors);
	free(all->map->textures->north_path);
	free(all->map->textures->south_path);
	free(all->map->textures->east_path);
	free(all->map->textures->west_path);
	free(all->map->textures->door);
	free(all->map->textures);
	free(all->connection);
	// free(all->window);
	free(all->buffer.screen);
	free(all->map->map);
	exit(0);
}

int	key_hook(int key, t_mlx *all)
{
	float	next_x;
	float	next_y;
	float	speed;
	float	px;
	float	py;

	next_x = all->map->player_x;
	next_y = all->map->player_y;
	speed = 0.10;
	px = all->map->player_x;
	py = all->map->player_y;
	if (all->map->angle < 0)
		all->map->angle += 2 * M_PI;
	else if (all->map->angle > 2 * M_PI)
		all->map->angle -= 2 * M_PI;
	if (key == LEFT)
	{
		next_x = px + cos(all->map->angle - M_PI / 2) * speed;
		next_y = py - sin(all->map->angle - M_PI / 2) * speed;
	}
	else if (key == RIGHT)
	{
		next_x = px + cos(all->map->angle + M_PI / 2) * speed;
		next_y = py - sin(all->map->angle + M_PI / 2) * speed;
	}
	else if (key == UP)
	{
		next_x = px + cos(all->map->angle) * speed;
		next_y = py - sin(all->map->angle) * speed;
	}
	else if (key == DOWN)
	{
		next_x = px - cos(all->map->angle) * speed;
		next_y = py + sin(all->map->angle) * speed;
	}
	else if (key == RIGHT_KEY)
		all->map->angle -= ROTATION_SPEED;
	else if (key == LEFT_KEY)
		all->map->angle += ROTATION_SPEED;
	else if (key == SPACE)
		handle_space_key(all);
	else if (key == ESCAPE)
		free_exit(all);
	if (all->map->map[(int)next_y][(int)px] != '1'
		&& all->map->map[(int)next_y][(int)px] != 'D')
		all->map->player_y = next_y;
	if (all->map->map[(int)py][(int)next_x] != '1'
		&& all->map->map[(int)py][(int)next_x] != 'D')
		all->map->player_x = next_x;
	mlx_clear_window(all->connection, all->window);
	ray_casting(all);
	draw_minimap(all);
	return (0);
}
