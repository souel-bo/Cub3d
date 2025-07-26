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
	float(first_horz_y), (first_horz_x), (Ya), (Xa);
	if (sin(all->map->angle) > 0)
		first_horz_y = floor(all->map->player_y) * TILE_SIZE - 1;
	else
		first_horz_y = floor(all->map->player_y) * TILE_SIZE + TILE_SIZE;
	if (fabs(sin(all->map->angle)) < 0.0001f)
		first_horz_x = all->map->player_x;
	else
		first_horz_x = (all->map->player_x * 32) + (first_horz_y
				- (all->map->player_y * 32)) / tan(all->map->angle);
	if (sin(all->map->angle) > 0)
		Ya = -TILE_SIZE;
	else
		Ya = TILE_SIZE;
	Xa = Ya / tan(all->map->angle);
}

void	vertical(t_mlx *all)
{
	float(first_vert_y), (first_vert_x), (Ya), (Xa);
	if (cos(all->map->angle) > 0)
		first_vert_x = floor((all->map->player_x * 32) / TILE_SIZE) * TILE_SIZE
			+ TILE_SIZE;
	else
		first_vert_x = floor((all->map->player_x * 32) / TILE_SIZE) * TILE_SIZE
			- 1;
	first_vert_y = (all->map->player_y * 32) + ((all->map->player_x)
			- first_vert_x) * tan(all->map->angle);
	if (cos(all->map->angle) > 0)
		Xa = TILE_SIZE;
	else
		Xa = -TILE_SIZE;
	Ya = Xa * tan(all->map->angle);
}

void	dda_algorithm(t_mlx *all, float angle)
{
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