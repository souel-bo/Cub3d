/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/30 15:47:41 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

void	draw_player(t_mlx *all)
{
	mlx_put_image_to_window(all->connection, all->window,
		all->buffer.player.img, (int)(all->map->player_x * 32 - 16),
		(int)(all->map->player_y * 32 - 16));
}

// void	draw_single_ray(t_mlx *all)
// {
// 	float	ray_x;
// 	float	ray_y;
// 	float	angle;
// 	float	step;

// 	ray_x = all->map->player_x;
// 	ray_y = all->map->player_y;
// 	angle = all->map->angle;
// 	step = 0.01;
// 	while (1)
// 	{
// 		printf("ray_x : %f\n", cos(angle));
// 		printf("ray_y : %f\n", sin(angle));
// 		ray_x += cos(angle) * step;
// 		ray_y -= sin(angle) * step;
// 		if (all->map->map[(int)ray_y][(int)ray_x] == '1')
// 			break ;
// 		// usleep(100);
// 		mlx_pixel_put(all->connection, all->window, ray_x * 32, ray_y * 32,
// 			YELLOW);
// 	}
// }

void	draw_map(t_mlx *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map->map[i])
	{
		j = 0;
		while (all->map->map[i][j])
		{
			if (all->map->map[i][j] == '1')
				mlx_put_image_to_window(all->connection, all->window,
					all->buffer.wall.img, j * 32, i * 32);
			else if (all->map->map[i][j] == 'D')
				mlx_put_image_to_window(all->connection, all->window,
					all->buffer.door.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
	draw_player(all);
	draw_single_ray(all);
}

int	key_hook(int key, t_mlx *all)
{
	float	next_x;
	float	next_y;
	float	speed;
	float	px;
	float	py;
	// printf("Keycode: %d\n", key);
	next_x = all->map->player_x;
	next_y = all->map->player_y;
	speed = 0.10;
	px = all->map->player_x;
	py = all->map->player_y;
	if (all->map->angle < 0)
		all->map->angle += 2 * M_PI;
	else if (all->map->angle > 2 * M_PI)
		all->map->angle -= 2 * M_PI;
	if (key == RIGHT)
	{
		next_x = px + cos(all->map->angle - M_PI / 2) * speed;
		next_y = py - sin(all->map->angle - M_PI / 2) * speed;
	}
	else if (key == LEFT)
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
	else if (key == LEFT_KEY) 
		all->map->angle -= ROTATION_SPEED;
	else if (key == RIGHT_KEY) 
		all->map->angle += ROTATION_SPEED;
	else if (key == ESCAPE)
		exit(0);
	if (all->map->map[(int)next_y][(int)px] != '1')
	all->map->player_y = next_y;
if (all->map->map[(int)py][(int)next_x] != '1')
	all->map->player_x = next_x;
	mlx_clear_window(all->connection, all->window);
	draw_map(all);
	return (0);
}
