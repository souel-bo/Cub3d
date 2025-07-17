/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/17 16:09:36 by souel-bo         ###   ########.fr       */
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
	else if (key == ESCAPE)
		exit(0);
	if (all->map->map[(int)(next_y - 0.47)][(int)(next_x + 0.47)] != '1'
		&& all->map->map[(int)(next_y + 0.47)][(int)(next_x + 0.47)] != '1'
		&& all->map->map[(int)(next_y - 0.47)][(int)(next_x - 0.47)] != '1'
		&& all->map->map[(int)(next_y + 0.47)][(int)(next_x - 0.47)] != '1')
	{
		all->map->player_x = next_x;
		all->map->player_y = next_y;
	}
	mlx_clear_window(all->connection, all->window);
	draw_map(all);
	return (0);
}
