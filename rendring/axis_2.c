/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:21:00 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/31 23:07:18 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

static void	init_ray_data(t_norm *ray, t_mlx *all, float angle)
{
	ray->px = all->map->player_x;
	ray->py = all->map->player_y;
	ray->raydirx = cos(angle);
	ray->raydiry = -sin(angle);
	ray->mapx = (int)ray->px;
	ray->mapy = (int)ray->py;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
	ray->side = 0;
}

static void	setup_ray_steps(t_norm *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->px - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->px) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->py - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->py) * ray->deltadisty;
	}
}

static void	perform_dda(t_norm *ray, t_mlx *all)
{
	while (!ray->hit)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (ray->mapx < 0 || ray->mapy < 0
			|| ray->mapy >= ft_count_argc(all->map->map)
			|| ray->mapx >= (int)strlen(all->map->map[ray->mapy]))
		{
			ray->hit = 1;
		}
		if (all->map->map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
		if (all->map->map[ray->mapy][ray->mapx] == 'D')
			ray->hit = 2;
	}
}

static void	calculate_distance(t_norm *ray, t_mlx *all, float angle)
{
	if (ray->side == 0)
		ray->perpwall = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwall = (ray->sidedisty - ray->deltadisty);
	ray->perpwall *= cos(angle - all->map->angle);
	ray->perpwall *= TILE_SIZE;
}

void	ray_line(t_mlx *all, float angle, int j)
{
	t_norm	ray;

	init_ray_data(&ray, all, angle);
	setup_ray_steps(&ray);
	perform_dda(&ray, all);
	calculate_distance(&ray, all, angle);
	ray.j = j;
	draw_viewd_ray(all, &ray);
}
