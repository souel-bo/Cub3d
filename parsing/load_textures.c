/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:14:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/04 11:54:21 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	load_north_texture(t_mlx *all, int *width, int *height)
{
	all->buffer.north.img = mlx_xpm_file_to_image(all->connection,
			all->map->textures->north_path, width, height);
	if (!all->buffer.north.img)
	{
		perror("Failed to load north texture");
		free_exit(all);
	}
	all->buffer.north.addr.addr = mlx_get_data_addr(all->buffer.north.img,
			&all->buffer.north.addr.bpp, &all->buffer.north.addr.size_len,
			&all->buffer.north.addr.endian);
}

static void	load_south_texture(t_mlx *all, int *width, int *height)
{
	all->buffer.south.img = mlx_xpm_file_to_image(all->connection,
			all->map->textures->south_path, width, height);
	if (!all->buffer.south.img)
	{
		perror("Failed to load south texture");
		free_exit(all);
	}
	all->buffer.south.addr.addr = mlx_get_data_addr(all->buffer.south.img,
			&all->buffer.south.addr.bpp, &all->buffer.south.addr.size_len,
			&all->buffer.south.addr.endian);
}

static void	load_east_texture(t_mlx *all, int *width, int *height)
{
	all->buffer.east.img = mlx_xpm_file_to_image(all->connection,
			all->map->textures->east_path, width, height);
	if (!all->buffer.east.img)
	{
		perror("Failed to load east texture");
		free_exit(all);
	}
	all->buffer.east.addr.addr = mlx_get_data_addr(all->buffer.east.img,
			&all->buffer.east.addr.bpp, &all->buffer.east.addr.size_len,
			&all->buffer.east.addr.endian);
}

static void	load_west_texture(t_mlx *all, int *width, int *height)
{
	all->buffer.west.img = mlx_xpm_file_to_image(all->connection,
			all->map->textures->west_path, width, height);
	if (!all->buffer.west.img)
	{
		perror("Failed to load west texture");
		free_exit(all);
	}
	all->buffer.west.addr.addr = mlx_get_data_addr(all->buffer.west.img,
			&all->buffer.west.addr.bpp, &all->buffer.west.addr.size_len,
			&all->buffer.west.addr.endian);
}

void	load_textures(t_mlx *all)
{
	int	width;
	int	height;

	load_door_texture(all, &width, &height);
	load_north_texture(all, &width, &height);
	load_south_texture(all, &width, &height);
	load_east_texture(all, &width, &height);
	load_west_texture(all, &width, &height);
}
