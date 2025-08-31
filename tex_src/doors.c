/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:35:36 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 19:42:30 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	calc_wall_x(t_mlx *all, t_norm *norm)
{
	if (norm->side == 0)
	{
		if (norm->raydirx > 0)
			norm->ray_2.wall_x = all->map->player_y + ((norm->mapx
						- all->map->player_x + 0.0) / norm->raydirx)
				* norm->raydiry;
		else
			norm->ray_2.wall_x = all->map->player_y + ((norm->mapx
						- all->map->player_x + 1.0) / norm->raydirx)
				* norm->raydiry;
	}
	else
	{
		if (norm->raydiry > 0)
			norm->ray_2.wall_x = all->map->player_x + ((norm->mapy
						- all->map->player_y + 0.0) / norm->raydiry)
				* norm->raydirx;
		else
			norm->ray_2.wall_x = all->map->player_x + ((norm->mapy
						- all->map->player_y + 1.0) / norm->raydiry)
				* norm->raydirx;
	}
	norm->ray_2.wall_x -= (int)norm->ray_2.wall_x;
}

static void	calc_tex_x(t_norm *norm)
{
	norm->ray_2.tex_x = (int)(norm->ray_2.wall_x * (double)TEX_W);
	if (norm->ray_2.tex_x < 0)
		norm->ray_2.tex_x = 0;
	if (norm->ray_2.tex_x >= TEX_W)
		norm->ray_2.tex_x = TEX_W - 1;
	if ((norm->side == 0 && norm->raydirx < 0) || (norm->side == 1
			&& norm->raydiry > 0))
		norm->ray_2.tex_x = TEX_W - norm->ray_2.tex_x - 1;
}

static int	init_ray_vars(t_mlx *all, t_norm *norm, t_img *tex)
{
	norm->ray_2.y0 = (int)norm->start;
	norm->ray_2.y1 = (int)norm->end;
	if (norm->ray_2.y0 < 0)
		norm->ray_2.y0 = 0;
	if (norm->ray_2.y1 > WIN_HEIGHT)
		norm->ray_2.y1 = WIN_HEIGHT;
	if (norm->ray_2.y0 >= norm->ray_2.y1)
		return (0);
	norm->ray_2.bytes_per_px = tex->addr.bpp >> 3;
	norm->ray_2.tex_line = tex->addr.size_len;
	norm->ray_2.step_fp = (int)((((long long)TEX_H) << 16)
			/ (int)norm->wall_size);
	norm->ray_2.texpos_fp = (int)(((long long)(norm->ray_2.y0
					- (int)norm->start) * norm->ray_2.step_fp));
	norm->ray_2.dst = all->map->pixels;
	norm->ray_2.x = norm->j;
	norm->ray_2.tex_base = tex->addr.addr;
	return (1);
}

static void	draw_ray_column(t_norm *norm)
{
	int	y;

	y = norm->ray_2.y0;
	while (y < norm->ray_2.y1)
	{
		norm->ray_2.tex_y = (norm->ray_2.texpos_fp >> 16);
		norm->ray_2.texpos_fp += norm->ray_2.step_fp;
		norm->ray_2.src = norm->ray_2.tex_base + norm->ray_2.tex_y
			* norm->ray_2.tex_line + norm->ray_2.tex_x
			* norm->ray_2.bytes_per_px;
		norm->ray_2.color = *(int *)norm->ray_2.src;
		norm->ray_2.dst[y * WIN_WIDTH + norm->ray_2.x] = norm->ray_2.color;
		y++;
	}
}

void	draw_textured_door(t_mlx *all, t_norm *norm)
{
	t_img	*tex;

	tex = &all->buffer.door;
	if (!tex || !tex->addr.addr || norm->wall_size <= 0.0)
		return ;
	calc_wall_x(all, norm);
	calc_tex_x(norm);
	if (!init_ray_vars(all, norm, tex))
		return ;
	draw_ray_column(norm);
}
