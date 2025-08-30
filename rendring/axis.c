/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:44:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 17:25:13 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"
#include "float.h"

void	draw_textured_door(t_mlx *all, t_norm *norm)
{
	t_img	*tex;

	tex = &all->buffer.door;
	if (!tex || !tex->addr.addr || norm->wall_size <= 0.0)
		return ;
	if (norm->side == 0)
		norm->ray_2.wall_x = all->map->player_y + ((norm->mapx - all->map->player_x + (1
						- (norm->raydirx > 0 ? 1 : -1)) / 2.0) / norm->raydirx) * norm->raydiry;
	else
		norm->ray_2.wall_x = all->map->player_x + ((norm->mapy - all->map->player_y + (1
						- (norm->raydiry > 0 ? 1 : -1)) / 2.0) / norm->raydiry) * norm->raydirx;
	norm->ray_2.wall_x -= (int)norm->ray_2.wall_x;
	norm->ray_2.tex_x = (int)(norm->ray_2.wall_x * (double)TEX_W);
	if (norm->ray_2.tex_x < 0)
		norm->ray_2.tex_x = 0;
	if (norm->ray_2.tex_x >= TEX_W)
		norm->ray_2.tex_x = TEX_W - 1;
	if ((norm->side == 0 && norm->raydirx < 0) || (norm->side == 1 && norm->raydiry > 0))
		norm->ray_2.tex_x = TEX_W - norm->ray_2.tex_x - 1;
	norm->ray_2.y0 = (int)norm->start;
	norm->ray_2.y1 = (int)norm->end;
	if (norm->ray_2.y0 < 0)
		norm->ray_2.y0 = 0;
	if (norm->ray_2.y1 > WIN_HEIGHT)
		norm->ray_2.y1 = WIN_HEIGHT;
	if (norm->ray_2.y0 >= norm->ray_2.y1)
		return ;
	norm->ray_2.bytes_per_px = tex->addr.bpp >> 3;
	norm->ray_2.tex_line = tex->addr.size_len;
	norm->ray_2.step_fp = (int)((((long long)TEX_H) << 16) / (int)norm->wall_size);
	norm->ray_2.texpos_fp = (int)(((long long)(norm->ray_2.y0 - (int)norm->start) * norm->ray_2.step_fp));
	norm->ray_2.dst = all->map->pixels;
	norm->ray_2.x = norm->j;
	norm->ray_2.tex_base = tex->addr.addr;
	for (int y = norm->ray_2.y0; y < norm->ray_2.y1; ++y)
	{
		norm->ray_2.tex_y = (norm->ray_2.texpos_fp >> 16);
		norm->ray_2.texpos_fp += norm->ray_2.step_fp;
		norm->ray_2.src = norm->ray_2.tex_base + norm->ray_2.tex_y * norm->ray_2.tex_line + norm->ray_2.tex_x * norm->ray_2.bytes_per_px;
		norm->ray_2.color = *(int *)norm->ray_2.src;
		norm->ray_2.dst[y * WIN_WIDTH + norm->ray_2.x] = norm->ray_2.color;
	}
}


void	draw_viewd_ray(t_mlx *all, t_norm *ray)
{
	int		WIN_HEIGHTeight;
	int		WIN_WIDTHidth;
	int		y;
	int		pixel_index;

	WIN_HEIGHTeight = 460;
	WIN_WIDTHidth = 1070;
	ray->wall_size = WIN_HEIGHTeight / (ray->perpwall / 32);
	ray->start = (WIN_HEIGHTeight - ray->wall_size) / 2;
	ray->end = ray->start + ray->wall_size;
	y = 0;
	while (y < (int)ray->start && y < WIN_HEIGHTeight)
	{
		pixel_index = y * WIN_WIDTHidth + ray->j;
		all->map->pixels[pixel_index] = all->map->ceilling_collor;
		y++;
	}
	y = (int)ray->start;
	if (ray->hit == 1)
		draw_textured_wall(all, ray);
	else
		draw_textured_door(all, ray);
	y = (int)ray->end;
	while (y < WIN_HEIGHTeight)
	{
		if (y >= 0)
		{
			pixel_index = y * WIN_WIDTHidth + ray->j;
			all->map->pixels[pixel_index] = all->map->flor_collor;
		}
		y++;
	}
}

void	ray_line(t_mlx *all, float angle, int j)
{
	t_norm	ray;
	int		i;
	double	px;
	double	py;
	double	deltaDistX;
	double	deltaDistY;
	double	x;
	double	y;
	int		draw_x;
	int		draw_y;

	i = 0;
	px = all->map->player_x;
	py = all->map->player_y;
	ray.raydirx = cos(angle);
	ray.raydiry = -sin(angle);
	ray.mapx = (int)px;
	ray.mapy = (int)py;
	deltaDistX = fabs(1 / ray.raydirx);
	deltaDistY = fabs(1 / ray.raydiry);
	int stepX, stepY;
	double sideDistX, sideDistY;
	if (ray.raydirx < 0)
	{
		stepX = -1;
		sideDistX = (px - ray.mapx) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (ray.mapx + 1.0 - px) * deltaDistX;
	}
	if (ray.raydiry < 0)
	{
		stepY = -1;
		sideDistY = (py - ray.mapy) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (ray.mapy + 1.0 - py) * deltaDistY;
	}
	ray.hit = 0;
	ray.side = 0;
	while (!ray.hit)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			ray.mapx += stepX;
			ray.side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			ray.mapy += stepY;
			ray.side = 1;
		}
		if (ray.mapx < 0 || ray.mapy < 0
			|| ray.mapy >= ft_count_argc(all->map->map)
			|| ray.mapx >= (int)strlen(all->map->map[ray.mapy]))
		{
			ray.hit = 1;
			break ;
		}
		if (all->map->map[ray.mapy][ray.mapx] == '1')
			ray.hit = 1;
		if (all->map->map[ray.mapy][ray.mapx] == 'D')
			ray.hit = 2;
	}
	if (ray.side == 0)
		ray.perpwall = (sideDistX - deltaDistX);
	else
		ray.perpwall = (sideDistY - deltaDistY);
	ray.perpwall *= cos(angle - all->map->angle);
	ray.perpwall *= TILE_SIZE;
	x = all->map->player_x * 32;
	y = all->map->player_y * 32;
	draw_x = 0;
	draw_y = 0;
	ray.j = j;
	draw_viewd_ray(all, &ray);
}

void	casting_rays(t_mlx *all)
{
	float	rayAngle;

	rayAngle = all->map->angle - (FOV / 2);
	for (int raycount = 0; raycount < RAY_NMB; raycount++)
	{
		ray_line(all, rayAngle, raycount);
		rayAngle += FOV / RAY_NMB;
	}
}

void	dda_algorithm(t_mlx *all)
{
	casting_rays(all);
}

void	draw_single_ray(t_mlx *all)
{
	dda_algorithm(all);
}

void	ray_casting(t_mlx *all)
{
	draw_single_ray(all);
	mlx_put_image_to_window(all->connection, all->window,
			all->buffer.screen->img, 0, 0);
}
