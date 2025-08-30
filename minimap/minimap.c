/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:58:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 22:53:25 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	setup_player_minimap(t_mlx *all)
{
	all->minimap.player_screen_x_f = all->minimap.minimap_x + MINIMAP_RADIUS
		* TILE_MINI_MAP;
	all->minimap.player_screen_y_f = all->minimap.minimap_y + MINIMAP_RADIUS
		* TILE_MINI_MAP;
	all->minimap.player_screen_x = (int)all->minimap.player_screen_x_f;
	all->minimap.player_screen_y = (int)all->minimap.player_screen_y_f;
	all->minimap.player_size = TILE_MINI_MAP / 2;
	if (all->minimap.player_size < 3)
		all->minimap.player_size = 3;
}

void	draw_player_direction_line(t_mlx *all)
{
	all->minimap.angle = all->map->angle;
	all->minimap.line_length = TILE_MINI_MAP * 2;
	all->minimap.i = 0;
	while (all->minimap.i < all->minimap.line_length)
	{
		all->minimap.px = all->minimap.player_screen_x
			+ (int)(cos(all->minimap.angle) * all->minimap.i);
		all->minimap.py = all->minimap.player_screen_y
			- (int)(sin(all->minimap.angle) * all->minimap.i);
		if (all->minimap.px >= all->minimap.minimap_x
			&& all->minimap.px < all->minimap.minimap_x + MINIMAP_SIZE
			&& all->minimap.py >= all->minimap.minimap_y
			&& all->minimap.py < all->minimap.minimap_y + MINIMAP_SIZE
			&& all->minimap.px < WIN_WIDTH && all->minimap.py < WIN_HEIGHT)
			all->map->pixels[all->minimap.py * WIN_WIDTH
				+ all->minimap.px] = 0xFFFF00;
		all->minimap.i++;
	}
}

void	draw_player_minimap(t_mlx *all)
{
	setup_player_minimap(all);
	draw_square(all);
	draw_player_direction_line(all);
}

void	draw_minimap_border(t_mlx *all)
{
	all->minimap.i = 0;
	while (all->minimap.i < MINIMAP_SIZE)
	{
		if (all->minimap.minimap_y < WIN_HEIGHT && all->minimap.minimap_x
			+ all->minimap.i < WIN_WIDTH)
			all->map->pixels[all->minimap.minimap_y * WIN_WIDTH
				+ (all->minimap.minimap_x + all->minimap.i)] = 0x808080;
		if (all->minimap.minimap_y + MINIMAP_SIZE - 1 < WIN_HEIGHT
			&& all->minimap.minimap_x + all->minimap.i < WIN_WIDTH)
			all->map->pixels[(all->minimap.minimap_y + MINIMAP_SIZE - 1)
				* WIN_WIDTH + (all->minimap.minimap_x
					+ all->minimap.i)] = 0x808080;
		if (all->minimap.minimap_y + all->minimap.i < WIN_HEIGHT
			&& all->minimap.minimap_x < WIN_WIDTH)
			all->map->pixels[(all->minimap.minimap_y + all->minimap.i)
				* WIN_WIDTH + all->minimap.minimap_x] = 0x808080;
		if (all->minimap.minimap_y + all->minimap.i < WIN_HEIGHT
			&& all->minimap.minimap_x + MINIMAP_SIZE - 1 < WIN_WIDTH)
			all->map->pixels[(all->minimap.minimap_y + all->minimap.i)
				* WIN_WIDTH + (all->minimap.minimap_x + MINIMAP_SIZE
					- 1)] = 0x808080;
		all->minimap.i++;
	}
}

void	draw_minimap(t_mlx *all)
{
	if (!all || !all->map || !all->map->map || !all->map->pixels)
		return ;
	all->minimap.minimap_x = 10;
	all->minimap.minimap_y = 10;
	all->minimap.player_x = all->map->player_x;
	all->minimap.player_y = all->map->player_y;
	all->minimap.map_rows = 0;
	while (all->map->map[all->minimap.map_rows])
		all->minimap.map_rows++;
	clear_minimap_bg(all);
	setup_minimap_bounds(all);
	draw_minimap_cells(all);
	draw_player_minimap(all);
	draw_minimap_border(all);
}
