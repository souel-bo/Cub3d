#include "../includes/rendering.h"
#include "float.h"

//int	get_map_width(char **map)
//{
//	int	max_width;
//	int	current_width;
//	int	i;

//	max_width = 0;
//	i = 0;
//	while (map[i])
//	{
//		current_width = 0;
//		while (map[i][current_width])
//			current_width++;
//		if (current_width > max_width)
//			max_width = current_width;
//		i++;
//	}
//	return (max_width);
//}

//int	get_map_height(char **map)
//{
//	int	height;

//	height = 0;
//	while (map[height])
//		height++;
//	return (height);
//}
void draw_textured_wall(t_mlx *all, int j, int y_start, int y_end,
                        double wall_height, int side,
                        double rayDirX, double rayDirY, int mapX, int mapY)
{
    t_img *texture = NULL;
    int tex_x, tex_y, color;
    int screen_width = 1070;
    int texture_width = 64;
    int texture_height = 64;
    int screen_y = y_start;
    char *tex_pixel;

    // 1. Choose texture
    if (side == 0)
        texture = (rayDirX > 0) ? &all->buffer.west : &all->buffer.east;
    else
        texture = (rayDirY > 0) ? &all->buffer.north : &all->buffer.south;

    // Safety check
    if (!texture || !texture->addr.addr)
        return;

    // 2. Compute wall_x
    double wall_x;
    if (side == 0)
        wall_x = all->map->player_y + ((mapX - all->map->player_x + (1 - (rayDirX > 0 ? 1 : -1)) / 2.0) / rayDirX) * rayDirY;
    else
        wall_x = all->map->player_x + ((mapY - all->map->player_y + (1 - (rayDirY > 0 ? 1 : -1)) / 2.0) / rayDirY) * rayDirX;
    wall_x -= floor(wall_x);

    // 3. Compute tex_x
    tex_x = (int)(wall_x * texture_width);
    if (tex_x < 0) tex_x = 0;
    if (tex_x >= texture_width) tex_x = texture_width - 1;
    if ((side == 0 && rayDirX < 0) || (side == 1 && rayDirY > 0))
        tex_x = texture_width - tex_x - 1;

    // 4. Loop over vertical pixels
    while (screen_y < y_end && screen_y < 460)
    {
        double tex_pos = (screen_y - y_start) * (double)texture_height / wall_height;
        tex_y = (int)tex_pos;
        if (tex_y < 0) tex_y = 0;
        if (tex_y >= texture_height) tex_y = texture_height - 1;

        int pixel_offset = tex_y * texture->addr.size_len + tex_x * (texture->addr.bpp / 8);
        if (pixel_offset < 0 || pixel_offset >= texture->addr.size_len * texture_height)
        {
            screen_y++;
            continue; // Avoid invalid access
        }

        tex_pixel = texture->addr.addr + pixel_offset;
        color = *(unsigned int *)tex_pixel;

        int screen_offset = screen_y * screen_width + j;
        if (screen_offset >= 0 && screen_offset < screen_width * 460)
            all->map->pixels[screen_offset] = color;

        screen_y++;
    }
}



void	draw_viewd_ray(t_mlx *all, double perpWall, int j, int hit,
						int side, double rayDirX, double rayDirY,
						int mapX, int mapY)

{
	int		screen_height;
	int		screen_width;
	double	wallsize;
	double	start;
	double	end;
	int		y;
	int		pixel_index;

	screen_height = 460;
	screen_width = 1070;
	wallsize = screen_height / (perpWall / 32);
	start = (screen_height - wallsize) / 2;
	end = start + wallsize;
	y = 0;
	while (y < (int)start && y < screen_height)
	{
		//sky drawing
		pixel_index = y * screen_width + j;
		all->map->pixels[pixel_index] = all->map->ceilling_collor;
		y++;
	}
	y = (int)start;
	if (hit == 1)
	draw_textured_wall(all, j, (int)start, (int)end, wallsize, side,
		rayDirX, rayDirY, mapX, mapY);
	else
	{
		//doors drawing 
		while (y < (int)end && y < screen_height)
		{
			if (y >= 0)
			{
				pixel_index = y * screen_width + j;
				all->map->pixels[pixel_index] = 0x99999;
			}
			y++;
		}
	}
	y = (int)end ;
    while (y < screen_height)
	{
		//ground drawing
		if (y >= 0)
		{
			pixel_index = y * screen_width + j;
			all->map->pixels[pixel_index] =  all->map->flor_collor;
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
		if (mapX < 0 || mapY < 0 || mapY >= ft_count_argc(all->map->map) ||
			mapX >= (int)strlen(all->map->map[mapY]))
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