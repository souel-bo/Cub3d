/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/29 16:11:46 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

void	draw_player(t_mlx *all)
{
	mlx_put_image_to_window(all->connection, all->window,
		all->buffer.player.img, (int)(all->map->player_x * 32 - 16),
		(int)(all->map->player_y * 32 - 16));
}


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
	ray_casting(all);
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
	if (all->map->map[(int)(next_y )][(int)(next_x)] != '1'
		&& all->map->map[(int)(next_y)][(int)(next_x)] != '1'
		&& all->map->map[(int)(next_y )][(int)(next_x )] != '1'
		&& all->map->map[(int)(next_y)][(int)(next_x )] != '1')
	{
		all->map->player_x = next_x;
		all->map->player_y = next_y;
	}
	mlx_clear_window(all->connection, all->window);
	draw_map(all);
	return (0);
}
