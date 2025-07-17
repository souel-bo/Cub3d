/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:36:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/17 16:10:01 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

#include "cub.h"


void fill_wall_door(t_mlx *all);
void	get_player_position(t_map *units);
void	get_angle(t_map *units, char direction);
void	init_images(t_mlx *all);
void	get_adresses(t_mlx *all);
void	fill_wall_door(t_mlx *all);
int	key_hook(int key, t_mlx *all);
void	draw_map(t_mlx *all);
void	draw_player(t_mlx *all);
#endif