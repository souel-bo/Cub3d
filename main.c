/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/17 16:09:08 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int	main(int argc, char **argv)
{
	t_map units;
	t_mlx all;
	int i;
	i = 0;
	units.player_x = 0;
	units.player_y = 0;
	if (start_parsing(&units, argv))
		return (printf("map not valid\n"), 1);
	get_player_position(&units);
	all.connection = mlx_init();
	all.map = &units;
	all.window = mlx_new_window(all.connection, 1100, 600, "Cub3D");
	init_images(&all);
	get_adresses(&all);
	fill_wall_door(&all);
	draw_map(&all);
	mlx_hook(all.window, 2, 1L << 0, key_hook, &all);
	mlx_loop(all.connection);
}
