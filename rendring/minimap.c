/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:58:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/23 18:24:44 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void draw_square(t_mlx *all, int x, int y, int size, int color)
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
    if (!all || !all->map || !all->map->map || !all->map->pixels)
        return;
    int minimap_x = 10;
    int minimap_y = 10;
    float player_x = all->map->player_x;
    float player_y = all->map->player_y;
    int map_rows = 0;
    while (all->map->map[map_rows])
        map_rows++;
    for (int y = 0; y < MINIMAP_SIZE; y++)
        for (int x = 0; x < MINIMAP_SIZE; x++)
            if (minimap_x + x < WIN_WIDTH && minimap_y + y < WIN_HEIGHT)
                all->map->pixels[(minimap_y + y) * WIN_WIDTH + (minimap_x + x)] = 0x000000;
    float start_row_f = player_y - MINIMAP_RADIUS;
    float end_row_f   = player_y + MINIMAP_RADIUS;
    float start_col_f = player_x - MINIMAP_RADIUS;
    float end_col_f   = player_x + MINIMAP_RADIUS;

    int start_row = (int)floor(start_row_f);
    int end_row   = (int)ceil(end_row_f);
    int start_col = (int)floor(start_col_f);
    int end_col   = (int)ceil(end_col_f);

    for (int row = start_row; row <= end_row; row++)
    {
        if (row < 0 || row >= map_rows) continue;
        int map_len = (int)strlen(all->map->map[row]);

        for (int col = start_col; col <= end_col; col++)
        {
            if (col < 0 || col >= map_len) continue;
            char tile = all->map->map[row][col];
            int color;
            if (tile == '1') color = 0xFFFFFF;
            else if (tile == 'D') color = 0x00FF00;
            else if (tile == '0' || tile == ' ') color = 0x404040;
            else continue;
            float relative_x = col - player_x;
            float relative_y = row - player_y;
            float screen_x_f = minimap_x + (relative_x + MINIMAP_RADIUS) * TILE_MINI_MAP;
            float screen_y_f = minimap_y + (relative_y + MINIMAP_RADIUS) * TILE_MINI_MAP;
            
            int screen_x = (int)screen_x_f;
            int screen_y = (int)screen_y_f;
            for (int i = 0; i <= TILE_MINI_MAP; i++)
            {
                for (int j = 0; j <= TILE_MINI_MAP; j++)
                {
                    int px = screen_x + j;
                    int py = screen_y + i;

                    if (px >= minimap_x && px < minimap_x + MINIMAP_SIZE &&
                        py >= minimap_y && py < minimap_y + MINIMAP_SIZE &&
                        px < WIN_WIDTH && py < WIN_HEIGHT)
                        all->map->pixels[py * WIN_WIDTH + px] = color;
                }
            }
        }
    }
    float player_screen_x_f = minimap_x + MINIMAP_RADIUS * TILE_MINI_MAP;
    float player_screen_y_f = minimap_y + MINIMAP_RADIUS * TILE_MINI_MAP;
    
    int player_screen_x = (int)player_screen_x_f;
    int player_screen_y = (int)player_screen_y_f;
    int player_size = TILE_MINI_MAP / 2;
    if (player_size < 3) player_size = 3;
    draw_square(all, player_screen_x - player_size / 2, player_screen_y - player_size / 2, player_size, 0xFF0000);
    float angle = all->map->angle;
    int line_length = TILE_MINI_MAP * 2;
    for (int i = 0; i < line_length; i++)
    {
        int px = player_screen_x + (int)(cos(angle) * i);
        int py = player_screen_y - (int)(sin(angle) * i);
        
        if (px >= minimap_x && px < minimap_x + MINIMAP_SIZE &&
            py >= minimap_y && py < minimap_y + MINIMAP_SIZE &&
            px < WIN_WIDTH && py < WIN_HEIGHT)
            all->map->pixels[py * WIN_WIDTH + px] = 0xFFFF00;
    }
    for (int i = 0; i < MINIMAP_SIZE; i++)
    {
        if (minimap_y < WIN_HEIGHT && minimap_x + i < WIN_WIDTH)
            all->map->pixels[minimap_y * WIN_WIDTH + (minimap_x + i)] = 0x808080;
        if (minimap_y + MINIMAP_SIZE - 1 < WIN_HEIGHT && minimap_x + i < WIN_WIDTH)
            all->map->pixels[(minimap_y + MINIMAP_SIZE - 1) * WIN_WIDTH + (minimap_x + i)] = 0x808080;
        if (minimap_y + i < WIN_HEIGHT && minimap_x < WIN_WIDTH)
            all->map->pixels[(minimap_y + i) * WIN_WIDTH + minimap_x] = 0x808080;
        if (minimap_y + i < WIN_HEIGHT && minimap_x + MINIMAP_SIZE - 1 < WIN_WIDTH)
            all->map->pixels[(minimap_y + i) * WIN_WIDTH + (minimap_x + MINIMAP_SIZE - 1)] = 0x808080;
    }
}