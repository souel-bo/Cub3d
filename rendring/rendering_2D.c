/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/31 15:22:21 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

static void	normalize_angle(t_mlx *all)
{
	if (all->map->angle < 0)
		all->map->angle += 2 * M_PI;
	else if (all->map->angle > 2 * M_PI)
		all->map->angle -= 2 * M_PI;
}

static void	handle_move_keys(int key, t_mlx *all, float *next_x, float *next_y)
{
	all->px = all->map->player_x;
	all->py = all->map->player_y;
	all->speed = 0.10;
	if (key == LEFT)
	{
		*next_x = all->px + cos(all->map->angle - M_PI / 2) * all->speed;
		*next_y = all->py - sin(all->map->angle - M_PI / 2) * all->speed;
	}
	else if (key == RIGHT)
	{
		*next_x = all->px + cos(all->map->angle + M_PI / 2) * all->speed;
		*next_y = all->py - sin(all->map->angle + M_PI / 2) * all->speed;
	}
	else if (key == UP)
	{
		*next_x = all->px + cos(all->map->angle) * all->speed;
		*next_y = all->py - sin(all->map->angle) * all->speed;
	}
	else if (key == DOWN)
	{
		*next_x = all->px - cos(all->map->angle) * all->speed;
		*next_y = all->py + sin(all->map->angle) * all->speed;
	}
}

static void	handle_action_keys(int key, t_mlx *all)
{
	if (key == RIGHT_KEY)
		all->map->angle -= ROTATION_SPEED;
	else if (key == LEFT_KEY)
		all->map->angle += ROTATION_SPEED;
	else if (key == SPACE)
		handle_space_key(all);
	else if (key == ESCAPE)
		free_exit(all);
}

static void	apply_movement(t_mlx *all, float next_x, float next_y)
{
	int	px;
	int	py;

	px = (int)all->map->player_x;
	py = (int)all->map->player_y;
	if (all->map->map[(int)next_y][px] != '1'
		&& all->map->map[(int)next_y][px] != 'D')
		all->map->player_y = next_y;
	if (all->map->map[py][(int)next_x] != '1'
		&& all->map->map[py][(int)next_x] != 'D')
		all->map->player_x = next_x;
}

int	key_hook(int key, t_mlx *all)
{
	float	next_x;
	float	next_y;

	next_x = all->map->player_x;
	next_y = all->map->player_y;
	normalize_angle(all);
	handle_move_keys(key, all, &next_x, &next_y);
	handle_action_keys(key, all);
	apply_movement(all, next_x, next_y);
	mlx_clear_window(all->connection, all->window);
	ray_casting(all);
	draw_minimap(all);
	return (0);
}
