/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/01 10:55:09 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

#include "includes/libft.h"

int	main(int argc, char **argv)
{
	t_map units;
	t_mlx all;
	int i;
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
        mix_colors(&all);
        all.window = mlx_new_window(all.connection, 1070, 460, "Cub3D");
        all.buffer.screen = malloc(sizeof(t_img));
        all.buffer.screen->img = mlx_new_image(all.connection, 1070, 460);
        all.buffer.screen->addr.addr = mlx_get_data_addr(all.buffer.screen->img,
                &all.buffer.screen->addr.bpp, &all.buffer.screen->addr.size_len,
                &all.buffer.screen->addr.endian);
        all.map->pixels = (int *)all.buffer.screen->addr.addr;
        ray_casting(&all);
        mlx_hook(all.window, 2, 1L << 0, key_hook, &all);
        mlx_loop(all.connection);
    }
	//free_all_items(&units);
}