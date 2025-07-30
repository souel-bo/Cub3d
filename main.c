/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/30 15:17:29 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

#include "includes/libft.h"

int handle_mouse_movements(int x, int y, void *param)
{
	t_mlx *all = (t_mlx *)param;

	int delta = x - MOUSE_CENTER_X;
	if (delta == 0)
		return (0);
	all->map->angle += delta * 0.001;
	if (all->map->angle > 2 * M_PI)
		all->map->angle -= 2 * M_PI;
	else if (all->map->angle < 0)
		all->map->angle += 2 * M_PI;
	mlx_mouse_move(all->connection, all->window, MOUSE_CENTER_X, WIN_HEIGHT / 2);
	mlx_clear_window(all->connection, all->window);
	draw_map(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	units;
	int		i;
	t_mlx	all;

	// int		i;
	i = 0;
	if (argc != 2 || ft_check_filename(argv[1]) || start_parsing(&units, argv))
		return (printf("map not valid\n"), 0);
	else
	{
		i = 0;
		units.player_x = 0;
		units.player_y = 0;
		get_player_position(&units);
		all.connection = mlx_init();
		all.map = &units;
		all.movements.movements = malloc(sizeof(int) * 6);
		all.movements.movements = ft_memset(all.movements.movements, 0,
				sizeof(int) * 6);
		all.window = mlx_new_window(all.connection, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
		init_images(&all);
		get_adresses(&all);
		fill_wall_door(&all);
		draw_map(&all);
		mlx_hook(all.window, 2, 1L << 0, key_hook, &all);
		mlx_mouse_hide(all.connection, all.window);
		mlx_hook(all.window, 6,  1L << 6, handle_mouse_movements, &all);
		mlx_loop(all.connection);
	}
	// free_all_items(&units);
}

