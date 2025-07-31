/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/31 21:39:42 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

void	draw_walls(t_mlx *all)
{
	mlx_put_image_to_window(all->connection, all->window, all->buffer.screen->img ,0, 0);
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
	speed = 0.20;
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
	else if (key == ESCAPE)
		exit(0);
	if (all->map->map[(int)(next_y )][(int)(next_x)] != '1'
		&& all->map->map[(int)(next_y)][(int)(next_x)] != '1'
		&& all->map->map[(int)(next_y )][(int)(next_x )] != '1'
		&& all->map->map[(int)(next_y)][(int)(next_x )] != '1')
	{
		all->map->player_x = next_x;
		all->map->player_y = next_y;
	}
	mlx_clear_window(all->connection, all->window);
	ray_casting(all);
	return (0);
}
