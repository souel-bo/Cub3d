/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:53:44 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 22:57:39 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_minimap_tile(t_mlx *all)
{
	all->minimap.i = 0;
	while (all->minimap.i <= TILE_MINI_MAP)
	{
		all->minimap.j = 0;
		while (all->minimap.j <= TILE_MINI_MAP)
		{
			all->minimap.px = all->minimap.screen_x + all->minimap.j;
			all->minimap.py = all->minimap.screen_y + all->minimap.i;
			if (all->minimap.px >= all->minimap.minimap_x
				&& all->minimap.px < all->minimap.minimap_x + MINIMAP_SIZE
				&& all->minimap.py >= all->minimap.minimap_y
				&& all->minimap.py < all->minimap.minimap_y + MINIMAP_SIZE
				&& all->minimap.px < WIN_WIDTH && all->minimap.py < WIN_HEIGHT)
				all->map->pixels[all->minimap.py * WIN_WIDTH
					+ all->minimap.px] = all->minimap.color;
			all->minimap.j++;
		}
		all->minimap.i++;
	}
}

int	get_tile_color(char tile)
{
	if (tile == '1')
		return (0xFFFFFF);
	else if (tile == 'D')
		return (0x00FF00);
	else if (tile == '0' || tile == ' ')
		return (0x404040);
	return (-1);
}

void	setup_tile_screen_pos(t_mlx *all)
{
	all->minimap.relative_x = all->minimap.col - all->minimap.player_x;
	all->minimap.relative_y = all->minimap.row - all->minimap.player_y;
	all->minimap.screen_x_f = all->minimap.minimap_x + (all->minimap.relative_x
			+ MINIMAP_RADIUS) * TILE_MINI_MAP;
	all->minimap.screen_y_f = all->minimap.minimap_y + (all->minimap.relative_y
			+ MINIMAP_RADIUS) * TILE_MINI_MAP;
	all->minimap.screen_x = (int)all->minimap.screen_x_f;
	all->minimap.screen_y = (int)all->minimap.screen_y_f;
}

void	process_minimap_tile(t_mlx *all)
{
	all->minimap.tile = all->map->map[all->minimap.row][all->minimap.col];
	all->minimap.color = get_tile_color(all->minimap.tile);
	if (all->minimap.color == -1)
		return ;
	setup_tile_screen_pos(all);
	draw_minimap_tile(all);
}

void	draw_minimap_cells(t_mlx *all)
{
	all->minimap.row = all->minimap.start_row;
	while (all->minimap.row <= all->minimap.end_row)
	{
		if (all->minimap.row >= 0 && all->minimap.row < all->minimap.map_rows)
		{
			all->minimap.map_len = (int)ft_strlen(
					all->map->map[all->minimap.row]);
			all->minimap.col = all->minimap.start_col;
			while (all->minimap.col <= all->minimap.end_col)
			{
				if (all->minimap.col >= 0
					&& all->minimap.col < all->minimap.map_len)
					process_minimap_tile(all);
				all->minimap.col++;
			}
		}
		all->minimap.row++;
	}
}
