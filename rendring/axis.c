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



void ray_line(t_mlx *all, float angle, int j)
{
    int i = 0;
    // Convert player pixel position to grid coordinates
    double px = all->map->player_x;  // Already in grid coordinates
    double py = all->map->player_y;  // Already in grid coordinates
    
    // Use the angle parameter for ray direction - CORRECTED for Y-down coordinate system
    double rayDirX = cos(angle);
    double rayDirY = -sin(angle);  // Negate sin for Y-down coordinate system
    
    // Current map position
    int mapX = (int)px;
    int mapY = (int)py;
    
    // Calculate delta distances (avoid division by zero)
    double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
    double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
    
    // Calculate step direction and initial sideDist
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
    
    // Perform DDA with bounds checking
    int hit = 0;
    int side = 0;
    
    while (!hit)
    {
        // Jump to next grid line
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
        
        // Bounds checking before accessing map
        if (mapX < 0 || mapY < 0 || mapY >= ft_count_argc(all->map->map) || 
            mapX >= (int)strlen(all->map->map[mapY]))
        {
            hit = 1; // Treat out of bounds as wall
            break;
        }
        
        // Check if ray has hit a wall
        if (all->map->map[mapY][mapX] == '1') 
            hit = 1;
    }
    
    // Calculate perpendicular wall distance
    double perpWall;
    if (side == 0) 
        perpWall = (sideDistX - deltaDistX);
    else          
        perpWall = (sideDistY - deltaDistY);
    
    // Convert back to pixel coordinates for drawing
    perpWall *= TILE_SIZE;
    
    // Draw the ray - CORRECTED for consistent coordinate system
    double x = all->map->player_x * 32;  // Convert to pixel coordinates
    double y = all->map->player_y * 32;  // Convert to pixel coordinates
    int draw_x = 0;
    int draw_y = 0;
    
    for (i = 0; i < (int)perpWall; i++)
    {
        draw_x = (int)(x + cos(angle) * i);
        draw_y = (int)(y - sin(angle) * i);  // Use -sin for Y-down coordinate system
        mlx_pixel_put(all->connection, all->window, draw_x, draw_y, GREEN);
    }
    
    // You can add your 3D rendering function here
    // draw_view_ray(draw_x, draw_y, j, all);
}

void casting_rays(t_mlx *all) 
{
    float rayAngle = all->map->angle - (FOV / 2);
    for (int raycount = 0; raycount < RAY_NMB; raycount++) 
    {
        ray_line(all, rayAngle, raycount);
        rayAngle += FOV / RAY_NMB;
    }
}

void dda_algorithm(t_mlx *all)
{
	printf("angle : %f\n", all->map->angle);
    casting_rays(all);
}

void	draw_single_ray(t_mlx *all)
{
	dda_algorithm(all);
}

void	ray_casting(t_mlx *all)
{
	draw_single_ray(all);
}