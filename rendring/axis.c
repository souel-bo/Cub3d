/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:44:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/31 23:35:04 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"
#include "float.h"

void	draw_ceiling_and_floor(t_mlx *all, t_norm *ray, int wall_start,
		int wall_end)
{
	int	y;
	int	pixel_index;

	y = 0;
	while (y < wall_start && y < WIN_HEIGHT)
	{
		pixel_index = y * WIN_WIDTH + ray->j;
		all->map->pixels[pixel_index] = all->map->ceilling_collor;
		y++;
	}
	y = wall_end;
	while (y < WIN_HEIGHT)
	{
		if (y >= 0)
		{
			pixel_index = y * WIN_WIDTH + ray->j;
			all->map->pixels[pixel_index] = all->map->flor_collor;
		}
		y++;
	}
}

void	draw_viewd_ray(t_mlx *all, t_norm *ray)
{
	int	wall_start;
	int	wall_end;

	ray->wall_size = WIN_HEIGHT / (ray->perpwall / 32);
	ray->start = (WIN_HEIGHT - ray->wall_size) / 2;
	ray->end = ray->start + ray->wall_size;
	wall_start = (int)ray->start;
	wall_end = (int)ray->end;
	draw_ceiling_and_floor(all, ray, wall_start, wall_end);
	if (ray->hit == 1)
		draw_textured_wall(all, ray);
	else
		draw_textured_door(all, ray);
}

void	casting_rays(t_mlx *all)
{
	float	rayangle;
	int		raycount;

	raycount = 0;
	rayangle = all->map->angle - (FOV / 2);
	while (raycount < RAY_NMB)
	{
		ray_line(all, rayangle, raycount);
		rayangle += FOV / RAY_NMB;
		raycount++;
	}
}

void	draw_single_ray(t_mlx *all)
{
	casting_rays(all);
}

void	ray_casting(t_mlx *all)
{
	draw_single_ray(all);
	mlx_put_image_to_window(all->connection, all->window,
		all->buffer.screen->img, 0, 0);
}
