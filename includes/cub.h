/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 04:01:12 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/31 16:55:45 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define DOOR_TILE 32
# define WALL_TILE 32
#define TILE_SIZE 32
# define PLAYER_TILE 32
# define FOV_TILE 16
# define GREY 0x808080
# define GREEN 0x58EB34
# define RED 0xFF0000
#define YELLOW 0xFFFF00

# define RIGHT 100
# define DOWN 115
# define UP 119
# define LEFT 97
# define ESCAPE 65307
# define ROTATION_SPEED 0.05
# define LEFT_KEY 65363
# define RIGHT_KEY 65361
typedef struct s_flor_collors
{
	int					red;
	int					green;
	int					blue;

}						t_flor_collors;

typedef struct s_parse_file
{
	char				**step_one;
	char				**step_two;
	char				**step_three;
	char				**step_four;
}						t_parse_file;

typedef struct s_ceilling_collors
{
	int					red;
	int					green;
	int					blue;

}						t_ceilling_collors;

typedef struct s_textures
{
	char				*north_path;
	char				*west_path;
	char				*east_path;
	char				*south_path;

}						t_textures;

typedef struct s_map
{
	char				**map;
	int					direction;
	int					flor_collor;
	double				player_x;
	double				player_y;
	double				angle;
	int					ceilling_collor;
	t_textures			*textures;
	t_ceilling_collors	*ceilling_collors;
	t_flor_collors		*floor_collors;
	int					count_ceil;
	int					count_floor;
	int					n_count;
	int					w_count;
	int					e_count;
	int					s_count;

}						t_map;

typedef struct s_addr
{
	char				*addr;
	int					bpp;
	int					size_len;
	int					endian;
}						t_addr;

typedef struct s_img
{
	void				*img;
	t_addr				addr;
}						t_img;

typedef struct s_images
{
	t_img				wall;
	t_img				player;
	t_img				door;
	t_img				fov;
}						t_images;

typedef struct s_mlx
{
	void				*connection;
	void				*window;
	t_map				*map;
	t_images			buffer;
}						t_mlx;

# include "rendering.h"

int						is_map_line(char *str);
int						count_lines(char **argv);
int						start_parsing(t_map *units, char **argv);
int						is_map_line(char *str);
int						count_lines(char **argv);
int						start_parsing(t_map *units, char **argv);
int						make_map_cube(t_map *units);
int						setup_for_flood_fill(char **tmp_map);
int						biggest_line(char **map);
int						check_textures(char **textures, t_map *units);
int						check_colors(char *str, t_map *units);
int						ft_colors(char **colors, t_map *units);
int						ft_check_filename(char *str);
void					free_all_items(t_map *units);
void					free_arr(char **arr);

#endif
