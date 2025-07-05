/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/05 14:37:26 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

void	allocation(t_mlx *all)
{
	all->buffer = malloc(sizeof(t_images));
	all->buffer->addr = malloc(sizeof(t_addr));
}

void fill_wall(t_mlx *all, int collor)
{
	int i = 0;
	int j = 0;
	int offset;
	int bpp_bytes = all->buffer->addr->bpp / 8;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			offset = i * all->buffer->addr->size_len + j * bpp_bytes;
			*(unsigned int *)(all->buffer->addr->addr + offset) = collor;
			j++;
		}
		i++;
	}
}

void fill_player(t_mlx *all, int collor)
{
	int i = 0;
	int j = 0;
	int offset;
	int bpp_bytes = all->buffer->addr->bpp / 8;
	while (i < 25)
	{
		j = 0;
		while (j < 25)
		{
			offset = i * all->buffer->addr->size_len + j * bpp_bytes;
			*(unsigned int *)(all->buffer->addr->addr + offset) = collor;
			j++;
		}
		i++;
	}
}

void	set_walls(t_mlx *all)
{
	all->buffer->wall = mlx_new_image(all->connection, 32, 32);
	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->wall,
			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
			&all->buffer->addr->endien);
	fill_wall(all, 0xAAAAAA);
}

void set_player(t_mlx *all)
{
	all->buffer->player = mlx_new_image(all->connection, 25, 25);
	all->buffer->addr->addr = mlx_get_data_addr(all->buffer->player,
			&all->buffer->addr->bpp, &all->buffer->addr->size_len,
			&all->buffer->addr->endien);
	fill_player(all, 0xFF0000);
}

void	set_images(t_mlx *all)
{
	set_walls(all);
	set_player(all);
}

void	draw_map(t_mlx *all)
{
	int	i = 0, j;

	i = 0, j = 0;
	allocation(all);
	set_images(all);
	while (all->map->map[i])
	{
		j = 0;
		while (all->map->map[i][j])
		{
			if (all->map->map[i][j] == '1')
				mlx_put_image_to_window(all->connection, all->window, all->buffer->wall, j * 32, i *32);
			else if (all->map->map[i][j] == 'N')
				mlx_put_image_to_window(all->connection, all->window, all->buffer->player, j * 25, i *25);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map units;
	t_mlx all;
	int i;
	i = 0;
	if (start_parsing(&units, argv))
		return (printf("map not valid\n"), 0);
	while (units.map[i])
	{
		printf("%s", units.map[i]);
		i++;
	}
	all.connection = mlx_init();
	all.map = &units;
	all.window = mlx_new_window(all.connection, 1100, 600, "Cub3D");
	draw_map(&all);
	mlx_loop(all.connection);
}