/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:44:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/28 18:35:18 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"
#include "float.h"

void	draw_textured_door(t_mlx *all, int j, int y_start, int y_end,
		double wall_height, int side, double rayDirX, double rayDirY, int mapX,
		int mapY)
{
	t_img	*tex;
	double	wall_x;
	int		tex_x;
	int		y0;
	int		y1;
	int		bytes_per_px;
	int		tex_line;
	int		step_fp;
	int		texpos_fp;
	int		*dst;
	int		x;
	char	*tex_base;
	int		tex_y;
	char	*src;
	int		color;

	tex = &all->buffer.door;
	if (!tex || !tex->addr.addr || wall_height <= 0.0)
		return ;
	if (side == 0)
		wall_x = all->map->player_y + ((mapX - all->map->player_x + (1
						- (rayDirX > 0 ? 1 : -1)) / 2.0) / rayDirX) * rayDirY;
	else
		wall_x = all->map->player_x + ((mapY - all->map->player_y + (1
						- (rayDirY > 0 ? 1 : -1)) / 2.0) / rayDirY) * rayDirX;
	wall_x -= (int)wall_x;
	tex_x = (int)(wall_x * (double)TEX_W);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= TEX_W)
		tex_x = TEX_W - 1;
	if ((side == 0 && rayDirX < 0) || (side == 1 && rayDirY > 0))
		tex_x = TEX_W - tex_x - 1;
	y0 = y_start;
	y1 = y_end;
	if (y0 < 0)
		y0 = 0;
	if (y1 > WIN_HEIGHT)
		y1 = WIN_HEIGHT;
	if (y0 >= y1)
		return ;
	bytes_per_px = tex->addr.bpp >> 3;
	tex_line = tex->addr.size_len;
	step_fp = (int)((((long long)TEX_H) << 16) / (int)wall_height);
	texpos_fp = (int)(((long long)(y0 - y_start) * step_fp));
	dst = all->map->pixels;
	x = j;
	tex_base = tex->addr.addr;
	for (int y = y0; y < y1; ++y)
	{
		tex_y = (texpos_fp >> 16);
		texpos_fp += step_fp;
		src = tex_base + tex_y * tex_line + tex_x * bytes_per_px;
		color = *(int *)src;
		dst[y * WIN_WIDTH + x] = color;
	}
}
void	draw_textured_wall(t_mlx *all, int j, int y_start, int y_end,
		double wall_height, int side, double rayDirX, double rayDirY, int mapX,
		int mapY)
{
	t_img	*tex;
	double	wall_x;
	int		tex_x;
	int		y0;
	int		y1;
	int		bytes_per_px;
	int		tex_line;
	int		step_fp;
	int		texpos_fp;
	int		*dst;
	int		x;
	char	*tex_base;
	int		tex_y;
	char	*src;
	int		color;

	if (side == 0)
	{
		if (rayDirX > 0)
			tex = &all->buffer.west;
		else
			tex = &all->buffer.east;
	}
	else
	{
		if (rayDirY > 0)
			tex = &all->buffer.south;
		else
			tex = &all->buffer.north;
	}

	if (!tex || !tex->addr.addr || wall_height <= 0.0)
		return ;

	if (side == 0)
		wall_x = all->map->player_y + ((mapX - all->map->player_x + (1
						- (rayDirX > 0 ? 1 : -1)) / 2.0) / rayDirX) * rayDirY;
	else
		wall_x = all->map->player_x + ((mapY - all->map->player_y + (1
						- (rayDirY > 0 ? 1 : -1)) / 2.0) / rayDirY) * rayDirX;

	wall_x -= (int)wall_x;
	tex_x = (int)(wall_x * (double)TEX_W);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= TEX_W)
		tex_x = TEX_W - 1;

	if ((side == 0 && rayDirX < 0) || (side == 1 && rayDirY > 0))
		tex_x = TEX_W - tex_x - 1;

	y0 = y_start;
	y1 = y_end;
	if (y0 < 0)
		y0 = 0;
	if (y1 > WIN_HEIGHT)
		y1 = WIN_HEIGHT;
	if (y0 >= y1)
		return ;

	bytes_per_px = tex->addr.bpp >> 3;
	tex_line = tex->addr.size_len;
	step_fp = (int)((((long long)TEX_H) << 16) / (int)wall_height);
	texpos_fp = (int)(((long long)(y0 - y_start) * step_fp));
	dst = all->map->pixels;
	x = j;
	tex_base = tex->addr.addr;

	int y = y0;
	while (y < y1)
	{
		tex_y = (texpos_fp >> 16);
		texpos_fp += step_fp;
		src = tex_base + tex_y * tex_line + tex_x * bytes_per_px;
		color = *(int *)src;
		dst[y * WIN_WIDTH + x] = color;
		y++;
	}
}


void	draw_viewd_ray(t_mlx *all, t_norm *ray)
{
	int		WIN_HEIGHTeight;
	int		WIN_WIDTHidth;
	double	wallsize;
	double	start;
	double	end;
	int		y;
	int		pixel_index;

	WIN_HEIGHTeight = 460;
	WIN_WIDTHidth = 1070;
	wallsize = WIN_HEIGHTeight / (ray->perpwall / 32);
	start = (WIN_HEIGHTeight - wallsize) / 2;
	end = start + wallsize;
	y = 0;
	while (y < (int)start && y < WIN_HEIGHTeight)
	{
		pixel_index = y * WIN_WIDTHidth + ray->j;
		all->map->pixels[pixel_index] = all->map->ceilling_collor;
		y++;
	}
	y = (int)start;
	if (ray->hit == 1)
		draw_textured_wall(all, ray->j, (int)start, (int)end, wallsize, ray->side,
			ray->raydirx, ray->raydiry, ray->mapx, ray->mapy);
	else
		draw_textured_door(all, ray->j, (int)start, (int)end, wallsize, ray->side,
			ray->raydirx, ray->raydiry, ray->mapx, ray->mapy);
	y = (int)end;
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
	t_norm ray;
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
	deltaDistX = (ray.raydirx == 0) ? 1e30 : fabs(1 / ray.raydirx);
	deltaDistY = (ray.raydiry == 0) ? 1e30 : fabs(1 / ray.raydiry);
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
		if (ray.mapx < 0 || ray.mapy < 0 || ray.mapy >= ft_count_argc(all->map->map)
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