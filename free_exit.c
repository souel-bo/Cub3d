/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:09:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/02 00:52:55 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

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

void	free_exit(t_mlx *all)
{
	free_images(all);
	mlx_destroy_window(all->connection, all->window);
	mlx_destroy_display(all->connection);
	free(all->connection);
	ft_free();
	exit(0);
}
