/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:34:55 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 17:36:50 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_img	*choose_texture(t_mlx *all, t_norm *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydirx > 0)
			return (&all->buffer.west);
		else
			return (&all->buffer.east);
	}
	else
	{
		if (ray->raydiry > 0)
			return (&all->buffer.south);
		else
			return (&all->buffer.north);
	}
}

void	compute_wall_x(t_mlx *all, t_norm *ray)
{
	int	dir_fix;

	if (ray->side == 0)
	{
		if (ray->raydirx > 0)
			dir_fix = 1;
		else
			dir_fix = -1;
		ray->ray_2.wall_x = all->map->player_y + ((ray->mapx
					- all->map->player_x + (1 - dir_fix) / 2.0) / ray->raydirx)
			* ray->raydiry;
	}
	else
	{
		if (ray->raydiry > 0)
			dir_fix = 1;
		else
			dir_fix = -1;
		ray->ray_2.wall_x = all->map->player_x + ((ray->mapy
					- all->map->player_y + (1 - dir_fix) / 2.0) / ray->raydiry)
			* ray->raydirx;
	}
	ray->ray_2.wall_x -= (int)ray->ray_2.wall_x;
}
