/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:23:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 17:35:52 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	compute_tex_x(t_norm *ray)
{
	ray->ray_2.tex_x = (int)(ray->ray_2.wall_x * (double)TEX_W);
	if (ray->ray_2.tex_x < 0)
		ray->ray_2.tex_x = 0;
	if (ray->ray_2.tex_x >= TEX_W)
		ray->ray_2.tex_x = TEX_W - 1;
	if ((ray->side == 0 && ray->raydirx < 0) || (ray->side == 1
			&& ray->raydiry > 0))
		ray->ray_2.tex_x = TEX_W - ray->ray_2.tex_x - 1;
}

static int	compute_y_bounds(t_norm *ray)
{
	ray->ray_2.y0 = ray->start;
	ray->ray_2.y1 = ray->end;
	if (ray->ray_2.y0 < 0)
		ray->ray_2.y0 = 0;
	if (ray->ray_2.y1 > WIN_HEIGHT)
		ray->ray_2.y1 = WIN_HEIGHT;
	if (ray->ray_2.y0 >= ray->ray_2.y1)
		return (0);
	return (1);
}

static int	init_ray_step(t_mlx *all, t_norm *ray, t_img *tex)
{
	ray->ray_2.bytes_per_px = tex->addr.bpp >> 3;
	ray->ray_2.tex_line = tex->addr.size_len;
	ray->ray_2.step_fp = (int)((((long long)TEX_H) << 16)
			/ (int)ray->wall_size);
	ray->ray_2.texpos_fp = (int)(((long long)(ray->ray_2.y0 - ray->start)
				* ray->ray_2.step_fp));
	ray->ray_2.dst = all->map->pixels;
	ray->ray_2.x = ray->j;
	ray->ray_2.tex_base = tex->addr.addr;
	return (1);
}

static void	draw_vertical_line(t_norm *ray)
{
	int	y;

	y = ray->ray_2.y0;
	while (y < ray->ray_2.y1)
	{
		ray->ray_2.tex_y = (ray->ray_2.texpos_fp >> 16);
		ray->ray_2.texpos_fp += ray->ray_2.step_fp;
		ray->ray_2.src = ray->ray_2.tex_base + ray->ray_2.tex_y
			* ray->ray_2.tex_line + ray->ray_2.tex_x * ray->ray_2.bytes_per_px;
		ray->ray_2.color = *(int *)ray->ray_2.src;
		ray->ray_2.dst[y * WIN_WIDTH + ray->ray_2.x] = ray->ray_2.color;
		y++;
	}
}

void	draw_textured_wall(t_mlx *all, t_norm *ray)
{
	t_img	*tex;

	tex = choose_texture(all, ray);
	if (!tex || !tex->addr.addr || ray->wall_size <= 0.0)
		return ;
	compute_wall_x(all, ray);
	compute_tex_x(ray);
	if (!compute_y_bounds(ray))
		return ;
	if (!init_ray_step(all, ray, tex))
		return ;
	draw_vertical_line(ray);
}
