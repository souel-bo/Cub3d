/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/26 13:59:29 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int	key_press(int key, t_mlx *all)
{
	if (key == UP)
		all->movements.movements[W] = 1;
	else if (key == DOWN)
		all->movements.movements[S] = 1;
	else if (key == LEFT)
		all->movements.movements[A] = 1;
	else if (key == RIGHT)
		all->movements.movements[D] = 1;
	else if (key == LEFT_KEY)
		all->movements.movements[L] = 1;
	else if (key == RIGHT_KEY)
		all->movements.movements[R] = 1;
	for (int i = 0; i < 6; i++)
		printf("%d ", all->movements.movements[i]);
	printf("\n");
	return (0);
}

int	key_release(int key, t_mlx *all)
{
	if (key == UP)
		all->movements.movements[W] = 0;
	else if (key == DOWN)
		all->movements.movements[S] = 0;
	else if (key == LEFT)
		all->movements.movements[A] = 0;
	else if (key == RIGHT)
		all->movements.movements[D] = 0;
	else if (key == LEFT_KEY)
		all->movements.movements[L] = 0;
	else if (key == RIGHT_KEY)
		all->movements.movements[R] = 0;
	for (int i = 0; i < 6; i++)
		printf("%d ", all->movements.movements[i]);
	printf("\n");
	return (0);
}

// int	update(t_mlx *all)
// {
// 	float	next_x;
// 	float	next_y;
// 	float	speed;
// 	float	px;
// 	float	py;

// 	next_x = all->map->player_x;
// 	next_y = all->map->player_y;
// 	speed = 0.004;
// 	px = all->map->player_x;
// 	py = all->map->player_y;
// 	if (all->map->angle < 0)
// 		all->map->angle += 2 * M_PI;
// 	if (all->map->angle >= 2 * M_PI)
// 		all->map->angle -= 2 * M_PI;
// 	if (all->movements.movements[W])
// 	{
// 		next_x = px + cos(all->map->angle) * speed;
// 		next_y = py - sin(all->map->angle) * speed;
// 	}
// 	if (all->movements.movements[A])
// 	{
// 		next_x = px + cos(all->map->angle + M_PI / 2) * speed;
// 		next_y = py - sin(all->map->angle + M_PI / 2) * speed;
// 	}
// 	if (all->movements.movements[S])
// 	{
// 		next_x = px - cos(all->map->angle) * speed;
// 		next_y = py + sin(all->map->angle) * speed;
// 	}
// 	if (all->movements.movements[D])
// 	{
// 		next_x = px + cos(all->map->angle - M_PI / 2) * speed;
// 		next_y = py - sin(all->map->angle - M_PI / 2) * speed;
// 	}
// 	if (all->movements.movements[L])
// 		all->map->angle -= ROTATION_SPEED;
// 	if (all->movements.movements[R])
// 		all->map->angle += ROTATION_SPEED;
// 	if (all->map->map[(int)py][(int)next_x] != '1')
// 		all->map->player_x = next_x;
// 	if (all->map->map[(int)next_y][(int)px] != '1')
// 		all->map->player_y = next_y;
// 	mlx_clear_window(all->connection, all->window);
// 	draw_map(all);
// 	return (0);
// }

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
		all.window = mlx_new_window(all.connection, 1070, 460, "Cub3D");
		init_images(&all);
		get_adresses(&all);
		fill_wall_door(&all);
		draw_map(&all);
		mlx_hook(all.window, 2, 1L << 0, key_hook, &all);
		// for (int i = 0; i < 6; i++)
		// 	printf("%d\n", all.movements.movements[i]);
		// mlx_hook(all.window, 3, 1L << 1, key_release, &all);
		// mlx_loop_hook(all.connection, update, &all);
		mlx_loop(all.connection);
	}
	// free_all_items(&units);
}
