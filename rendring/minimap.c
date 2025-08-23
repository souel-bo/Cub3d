/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:58:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/23 11:57:12 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	draw_square(t_mlx *all, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int px = x + j;
			int py = y + i;
			if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
				all->map->pixels[py * WIN_WIDTH + px] = color;
		}
	}
}
void draw_minimap(t_mlx *all)
{
    int minimap_x = 10;
    int minimap_y = 10;
    if (!all || !all->map || !all->map->map || !all->map->pixels)
        return;
    float player_x = all->map->player_x;
    float player_y = all->map->player_y;
    for (int y = 0; y < MINIMAP_SIZE; y++)
    {
        for (int x = 0; x < MINIMAP_SIZE; x++)
        {
            int px = minimap_x + x;
            int py = minimap_y + y;
            if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
                all->map->pixels[py * WIN_WIDTH + px] = 0x000000;
        }
    }
    for (int i = 0; i < MINIMAP_SIZE; i++)
    {
        if (minimap_x + i >= 0 && minimap_x + i < WIN_WIDTH)
        {
            if (minimap_y >= 0 && minimap_y < WIN_HEIGHT)
                all->map->pixels[minimap_y * WIN_WIDTH + (minimap_x + i)] = 0xFFFFFF;
            if (minimap_y + MINIMAP_SIZE - 1 >= 0 && minimap_y + MINIMAP_SIZE - 1 < WIN_HEIGHT)
                all->map->pixels[(minimap_y + MINIMAP_SIZE - 1) * WIN_WIDTH + (minimap_x + i)] = 0xFFFFFF;
        }
        if (minimap_y + i >= 0 && minimap_y + i < WIN_HEIGHT)
        {
            if (minimap_x >= 0 && minimap_x < WIN_WIDTH)
                all->map->pixels[(minimap_y + i) * WIN_WIDTH + minimap_x] = 0xFFFFFF;
            if (minimap_x + MINIMAP_SIZE - 1 >= 0 && minimap_x + MINIMAP_SIZE - 1 < WIN_WIDTH)
                all->map->pixels[(minimap_y + i) * WIN_WIDTH + (minimap_x + MINIMAP_SIZE - 1)] = 0xFFFFFF;
        }
    }
    for (int dy = -MINIMAP_RADIUS - 1; dy <= MINIMAP_RADIUS + 1; dy++)
    {
        for (int dx = -MINIMAP_RADIUS - 1; dx <= MINIMAP_RADIUS + 1; dx++)
        {
            int map_x = (int)(player_x) + dx;
            int map_y = (int)(player_y) + dy;
            float player_offset_x = player_x - (int)player_x;
            float player_offset_y = player_y - (int)player_y;
            int screen_x = minimap_x + (dx + MINIMAP_RADIUS) * TILE_MINI_MAP - (int)(player_offset_x * TILE_MINI_MAP);
            int screen_y = minimap_y + (dy + MINIMAP_RADIUS) * TILE_MINI_MAP - (int)(player_offset_y * TILE_MINI_MAP);
            char tile = ' ';
            if (map_y >= 0 && all->map->map[map_y] && 
                map_x >= 0 && map_x < (int)strlen(all->map->map[map_y]))
            {
                tile = all->map->map[map_y][map_x];
            }
            int color;
            if (tile == '1') 
                color = 0xFFFFFF; 
            else if (tile == 'D') 
                color = 0x00FF00;
            else if (tile == '0' || tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W') // walkable
                color = 0x404040;
            else
                continue;
            for (int i = 0; i < TILE_MINI_MAP; i++)
            {
                for (int j = 0; j < TILE_MINI_MAP; j++)
                {
                    int px = screen_x + j;
                    int py = screen_y + i;
                    if (px > minimap_x && px < minimap_x + MINIMAP_SIZE - 1 && 
                        py > minimap_y && py < minimap_y + MINIMAP_SIZE - 1 &&
                        px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
                        all->map->pixels[py * WIN_WIDTH + px] = color;
                }
            }
        }
    }
    int center_x = minimap_x + MINIMAP_SIZE / 2;
    int center_y = minimap_y + MINIMAP_SIZE / 2;
    int player_size = TILE_MINI_MAP / 3;
    if (player_size < 4) player_size = 4;
    draw_square(all, center_x - player_size/2, center_y - player_size/2, 
               player_size, 0xFF0000);
    float angle = all->map->angle;
    int line_length = TILE_MINI_MAP;
    for (int i = 0; i < line_length; i++)
    {
        int px = center_x + (int)(cos(angle) * i);
        int py = center_y - (int)(sin(angle) * i);
        if (px >= minimap_x + 1 && px < minimap_x + MINIMAP_SIZE - 1 && 
            py >= minimap_y + 1 && py < minimap_y + MINIMAP_SIZE - 1)
            all->map->pixels[py * WIN_WIDTH + px] = 0xFFFF00;
    }
}