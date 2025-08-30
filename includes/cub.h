/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 04:01:12 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 19:06:47 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../get_next_line/get_next_line.h"
# include "libft.h"
# include "rendering.h"
# include "type.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define DOOR_TILE 32
# define WALL_TILE 32
# define PLAYER_TILE 32
# define TILE_SIZE 32
# define FOV_TILE 16
# define GREY 0x808080
# define GREEN 0x006400
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define RIGHT 100
# define DOWN 115
# define UP 119
# define LEFT 97
# define SPACE 32
# define ESCAPE 65307
# define ROTATION_SPEED 0.05
# define LEFT_KEY 65363
# define RIGHT_KEY 65361
# define WIN_WIDTH 1070
# define WIN_HEIGHT 460
# define TEX_W 64
# define TEX_H 64
# define MINIMAP_SIZE 150
# define MINIMAP_RADIUS 3
# define MOUSE_CENTER_X 960
# define MINIMAP_TILES 7
# define TILE_MINI_MAP 21

int		is_map_line(char *str);
int		count_lines(char **argv);
int		start_parsing(t_map *units, char **argv);
int		is_map_line(char *str);
int		count_lines(char **argv);
int		start_parsing(t_map *units, char **argv);
int		make_map_cube(t_map *units);
int		setup_for_flood_fill(char **tmp_map);
int		biggest_line(char **map);
int		check_textures(char **textures, t_map *units);
int		check_colors(char *str, t_map *units);
int		ft_colors(char **colors, t_map *units);
int		ft_check_filename(char *str);
void	free_all_items(t_map *units);
void	free_arr(char **arr);
void	mix_colors(t_mlx *all);
void	draw_minimap(t_mlx *all);
void	free_exit(t_mlx *all);
void	load_textures(t_mlx *all);
void	load_door_texture(t_mlx *all, int *width, int *height);
int		flood_fill(char **map, int x, int y);
int		*find_character(char **tmp_map);
char	**read_file(int fd);
int		is_valid_texture(char *str, t_textures *textures, t_map *units);
char	*remove_newline(char *str);

#endif