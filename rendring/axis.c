#include "../includes/rendering.h"

int	get_map_width(char **map)
{
	int	max_width;
	int	current_width;
	int	i;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		current_width = 0;
		while (map[i][current_width])
			current_width++;
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return (max_width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	dda_algorithm(t_mlx *all, float angle)
{
	int(map_height), (hit), (map_width), (map_x), (map_y);
	float(abs_x), (abs_y), (delta_x), (delta_y), (ray_x), (ray_y), (step_x),
		(step_y);
	map_height = get_map_height(all->map->map);
	map_width = get_map_width(all->map->map);
	hit = 0;
	ray_x = all->map->player_x * 32;
	ray_y = all->map->player_y * 32;
	delta_x = cos(angle);
	delta_y = -sin(angle);
	abs_x = fabs(delta_x);
	abs_y = fabs(delta_y);
	if (abs_x > abs_y)
	{
		if (delta_x > 0)
			step_x = 1;
		else
			step_x = -1;
		step_y = delta_y / abs_x;
	}
	else
	{
		if (delta_y > 0)
			step_y = 1;
		else
			step_y = -1;
		step_x = delta_x / abs_y;
	}
	while (!hit)
	{
		mlx_pixel_put(all->connection, all->window, (int)ray_x, (int)ray_y,
				GREEN);
		ray_x += step_x;
		ray_y += step_y;
		map_x = (int)(ray_x / 32);
		map_y = (int)(ray_y / 32);
		if (all->map->map[map_y][map_x] == '1')
			hit = 1;
	}
}

void	draw_single_ray(t_mlx *all)
{
	dda_algorithm(all, all->map->angle);
}
