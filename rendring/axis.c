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

void	horizontal(t_mlx *all)
{
	int	hit;
	int	map_x;
	int	map_y;
	float py = all->map->player_y * 32;
	float px = all->map->player_x * 32;

	hit = 0;
	float(first_horz_y), (first_horz_x), (Ya), (Xa);
	if (sin(all->map->angle) > 0)
	{
		first_horz_y = floor(all->map->player_y) * TILE_SIZE - 1;
		Ya = -TILE_SIZE;
	}
	else
	{
		first_horz_y = floor(py / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		Ya = TILE_SIZE;
	}
	if (fabs(sin(all->map->angle)) < 0)
	{
		first_horz_x = px;
		Xa = (cos(all->map->angle) > 0) ? TILE_SIZE : -TILE_SIZE;
	}
	else
	{
		first_horz_x = px + (first_horz_y
				- py) / tan(all->map->angle);
		Xa = Ya / tan(all->map->angle);
	}
	while (!hit)
	{
		map_x = (int)(first_horz_x / TILE_SIZE);
		map_y = (int)(first_horz_y / TILE_SIZE);
		if (map_x < 0 || map_y < 0 || map_y >= ft_count_argc(all->map->map) ||
			map_x >= (int)strlen(all->map->map[map_y]))
		{
			hit = 1;
			break ;
		}
		if (all->map->map[map_y][map_x] == '1')
			hit = 1;
		mlx_pixel_put(all->connection, all->window, first_horz_x, first_horz_y,
				GREEN);
		//printf("fhx : %f , fhy : %f\n", first_horz_x, first_horz_y);
		first_horz_x += Xa;
		first_horz_y += Ya;
	}
}

void	vertical(t_mlx *all)
{
	int	hit;
	int	map_x;
	int	map_y;

	hit = 0;
	float py = all->map->player_y * 32;
	float px = all->map->player_x * 32;

	float(first_vert_y), (first_vert_x), (Ya), (Xa);
	if (cos(all->map->angle) > 0)
	{
		first_vert_x = floor(px / TILE_SIZE) * TILE_SIZE
					+ TILE_SIZE;
		Xa = TILE_SIZE;
	}
	else
	{
		first_vert_x = floor(px / TILE_SIZE) * TILE_SIZE
					- 1;
		Xa = -TILE_SIZE;
	}
	if (fabs(cos(all->map->angle)) < 0.0001f)
		first_vert_y = py;
	else
		first_vert_y = py + (px
		 - first_vert_x) * tan(all->map->angle);
	Ya = Xa * tan(all->map->angle);
	while (!hit)
	{
		map_x = (int)(first_vert_x / TILE_SIZE);
		map_y = (int)(first_vert_y / TILE_SIZE);
		
		if (map_x < 0 || map_y < 0 || map_y >= ft_count_argc(all->map->map) || 
            map_x >= (int)strlen(all->map->map[map_y]))
        {
            hit = 1;  // Treat out-of-bounds as a wall hit
            break;
        }

		if (all->map->map[map_y][map_x] == '1')
			hit = 1;

		mlx_pixel_put(all->connection, all->window, first_vert_x, first_vert_y,
				YELLOW);
		first_vert_x += Xa;
		first_vert_y += Ya;
	}
}

void	dda_algorithm(t_mlx *all, float angle)
{
	printf("angle = %f\n", all->map->angle);
	horizontal(all);
	vertical(all);
}

void	draw_single_ray(t_mlx *all, float angle)
{
	dda_algorithm(all, angle);
}

void	ray_casting(t_mlx *all)
{
	draw_single_ray(all, all->map->angle);
}