/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/21 22:36:50 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int	main(int argc, char **argv)
{
	(void)argc;
int	main(int argc, char **argv)
{
	t_map units;
	int i;
	i = 0;
	if (argc != 2 || ft_check_filename(argv[1]) || start_parsing(&units, argv))
		return (printf("map not valid\n"), 0);
	else 
		printf("everything works 100%% \n");
	//while (units.map[i])
	//{
	//	printf("%s", units.map[i]);
	//	i++;
	//}
	free_all_items(&units);
}

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
	all.window = mlx_new_window(all.connection, 1070, 460, "Cub3D");
	init_images(&all);
	get_adresses(&all);
	fill_wall_door(&all);
	draw_map(&all);
	mlx_hook(all.window, 2, 1L << 0, key_hook, &all);
	mlx_loop(all.connection);
}
