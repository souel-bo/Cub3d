/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:09:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/31 15:10:22 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

static void	free_map(t_mlx *all)
{
	int	i;

	i = 0;
	while (all->map->map[i])
	{
		free(all->map->map[i]);
		i++;
	}
	free(all->map->map);
}

static void	free_images(t_mlx *all)
{
	if (all->buffer.door.img)
		mlx_destroy_image(all->connection, all->buffer.door.img);
	if (all->buffer.north.img)
		mlx_destroy_image(all->connection, all->buffer.north.img);
	if (all->buffer.south.img)
		mlx_destroy_image(all->connection, all->buffer.south.img);
	if (all->buffer.east.img)
		mlx_destroy_image(all->connection, all->buffer.east.img);
	if (all->buffer.west.img)
		mlx_destroy_image(all->connection, all->buffer.west.img);
	if (all->buffer.screen && all->buffer.screen->img)
		mlx_destroy_image(all->connection, all->buffer.screen->img);
}

static void	free_textures(t_mlx *all)
{
	free(all->map->ceilling_collors);
	free(all->map->floor_collors);
	free(all->map->textures->north_path);
	free(all->map->textures->south_path);
	free(all->map->textures->east_path);
	free(all->map->textures->west_path);
	free(all->map->textures->door);
	free(all->map->textures);
}

void	free_exit(t_mlx *all)
{
	free_map(all);
	free_images(all);
	mlx_destroy_window(all->connection, all->window);
	mlx_destroy_display(all->connection);
	free_textures(all);
	free(all->connection);
	free(all->buffer.screen);
	exit(0);
}
