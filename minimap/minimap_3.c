/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:54:16 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 22:57:47 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_square(t_mlx *all)
{
	int	i;
	int	j;
	int	px;
	int	py;

	i = 0;
	while (i < all->minimap.player_size)
	{
		j = 0;
		while (j < all->minimap.player_size)
		{
			px = all->minimap.player_screen_x - all->minimap.player_size / 2
				+ j;
			py = all->minimap.player_screen_y - all->minimap.player_size / 2
				+ i;
			if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
				all->map->pixels[py * WIN_WIDTH + px] = 0xFF0000;
			j++;
		}
		i++;
	}
}

void	clear_minimap_bg(t_mlx *all)
{
	all->minimap.y = 0;
	while (all->minimap.y < MINIMAP_SIZE)
	{
		all->minimap.x = 0;
		while (all->minimap.x < MINIMAP_SIZE)
		{
			if (all->minimap.minimap_x + all->minimap.x < WIN_WIDTH
				&& all->minimap.minimap_y + all->minimap.y < WIN_HEIGHT)
				all->map->pixels[(all->minimap.minimap_y + all->minimap.y)
					* WIN_WIDTH + (all->minimap.minimap_x
						+ all->minimap.x)] = 0x000000;
			all->minimap.x++;
		}
		all->minimap.y++;
	}
}

void	setup_minimap_bounds(t_mlx *all)
{
	all->minimap.start_row_f = all->minimap.player_y - MINIMAP_RADIUS;
	all->minimap.end_row_f = all->minimap.player_y + MINIMAP_RADIUS;
	all->minimap.start_col_f = all->minimap.player_x - MINIMAP_RADIUS;
	all->minimap.end_col_f = all->minimap.player_x + MINIMAP_RADIUS;
	all->minimap.start_row = (int)floor(all->minimap.start_row_f);
	all->minimap.end_row = (int)ceil(all->minimap.end_row_f);
	all->minimap.start_col = (int)floor(all->minimap.start_col_f);
	all->minimap.end_col = (int)ceil(all->minimap.end_col_f);
}
