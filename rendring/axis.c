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
		tex = (rayDirX > 0) ? &all->buffer.west : &all->buffer.east;
	else
		tex = (rayDirY > 0) ? &all->buffer.south : &all->buffer.north;
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

void	draw_viewd_ray(t_mlx *all, double perpWall, int j, int hit, int side,
		double rayDirX, double rayDirY, int mapX, int mapY)
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
	wallsize = WIN_HEIGHTeight / (perpWall / 32);
	start = (WIN_HEIGHTeight - wallsize) / 2;
	end = start + wallsize;
	y = 0;
	while (y < (int)start && y < WIN_HEIGHTeight)
	{
		// sky drawing
		pixel_index = y * WIN_WIDTHidth + j;
		all->map->pixels[pixel_index] = all->map->ceilling_collor;
		y++;
	}
	y = (int)start;
	if (hit == 1)
		draw_textured_wall(all, j, (int)start, (int)end, wallsize, side,
			rayDirX, rayDirY, mapX, mapY);
	else
		draw_textured_door(all, j, (int)start, (int)end, wallsize, side,
			rayDirX, rayDirY, mapX, mapY);
	y = (int)end;
	while (y < WIN_HEIGHTeight)
	{
		if (y >= 0)
		{
			pixel_index = y * WIN_WIDTHidth + j;
			all->map->pixels[pixel_index] = all->map->flor_collor;
		}
		y++;
	}
}

void	ray_line(t_mlx *all, float angle, int j)
{
	int		i;
	double	px;
	double	py;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	deltaDistX;
	double	deltaDistY;
	int		hit;
	int		side;
	double	perpWall;
	double	x;
	double	y;
	int		draw_x;
	int		draw_y;

	i = 0;
	px = all->map->player_x;
	py = all->map->player_y;
	rayDirX = cos(angle);
	rayDirY = -sin(angle);
	mapX = (int)px;
	mapY = (int)py;
	deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
	deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
	int stepX, stepY;
	double sideDistX, sideDistY;
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (px - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - px) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (py - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - py) * deltaDistY;
	}
	hit = 0;
	side = 0;
	while (!hit)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		if (mapX < 0 || mapY < 0 || mapY >= ft_count_argc(all->map->map)
			|| mapX >= (int)strlen(all->map->map[mapY]))
		{
			hit = 1;
			break ;
		}
		if (all->map->map[mapY][mapX] == '1')
			hit = 1;
		if (all->map->map[mapY][mapX] == 'D')
			hit = 2;
	}
	if (side == 0)
		perpWall = (sideDistX - deltaDistX);
	else
		perpWall = (sideDistY - deltaDistY);
	// fix eye problem fixed by this line . but who it works i dont know hhhhh
	perpWall *= cos(angle - all->map->angle);
	perpWall *= TILE_SIZE;
	x = all->map->player_x * 32;
	y = all->map->player_y * 32;
	draw_x = 0;
	draw_y = 0;
	draw_viewd_ray(all, perpWall, j, hit, side, rayDirX, rayDirY, mapX, mapY);
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