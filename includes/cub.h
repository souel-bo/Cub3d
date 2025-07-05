/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 04:01:12 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/05 10:04:17 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../get_next_line/get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

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
	char *addr;
	int bpp;
	int size_len;
	int endien;
} t_addr;

typedef struct s_images
{
	void *wall;
	void *player;
	void *door;
	t_addr *addr;
} t_images;


typedef struct s_mlx
{
	void *connection;
	void *window;
	t_map *map;
	t_images *buffer;
} t_mlx;


int is_map_line(char *str);
int count_lines(char **argv);
int start_parsing(t_map *units, char **argv);


#endif