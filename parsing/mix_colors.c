#include "../includes/cub.h"


int floor_color(t_mlx *all)
{
    int red = all->map->floor_collors->red;
    int green = all->map->floor_collors->green;
    int blue = all->map->floor_collors->blue;
    
    int floor_color = (red << 16) | (green << 8) | blue;
    return floor_color;
}

int ceil_color(t_mlx *all)
{
    int red = all->map->ceilling_collors->red;
    int green = all->map->ceilling_collors->green;
    int blue = all->map->ceilling_collors->blue;
    int ceil_color = (red << 16) | (green << 8) | blue;
    return ceil_color;
}

void mix_colors(t_mlx *all)
{
    all->map->ceilling_collor = ceil_color(all);
    all->map->flor_collor = floor_color(all);
}