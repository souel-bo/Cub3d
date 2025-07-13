/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 04:01:12 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/13 16:42:13 by souel-bo         ###   ########.fr       */
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
# include <unistd.h>
# define DOOR_TILE 32
# define WALL_TILE 32
# define PLAYER_TILE 15
# define FOV_TILE 16
# define GREY 0x808080
#define GREEN 0x006400

typedef struct s_flor_collors
{
	int					red;
	int					green;
	int					blue;
}						t_flor_collors;

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
	int					ceilling_collor;
	t_textures			*textures;
	t_ceilling_collors	*ceilling_collors;
	t_flor_collors		*floor_collors;
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
}			t_img;

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

#include "rendering.h"
int						is_map_line(char *str);
int						count_lines(char **argv);
int						start_parsing(t_map *units, char **argv);

#endif