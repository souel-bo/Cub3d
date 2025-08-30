/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:29:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 18:15:10 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "cub.h"

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
	char				*door;
}						t_textures;

typedef struct s_map
{
	char				**map;
	int					direction;
	int					flor_collor;
	int					*pixels;
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
	t_img				*screen;
	t_img				north;
	t_img				south;
	t_img				east;
	t_img				west;
	t_img				door;
}						t_images;

typedef struct s_movements
{
	int					*movements;
}						t_movements;

typedef struct s_norm_v2
{
	double				wall_x;
	int					tex_x;
	int					y0;
	int					y1;
	int					bytes_per_px;
	int					tex_line;
	int					step_fp;
	int					texpos_fp;
	int					*dst;
	int					x;
	char				*tex_base;
	int					tex_y;
	char				*src;
	int					color;
}						t_norm_v2;

typedef struct s_norm
{
	double				perpwall;
	int					j;
	int					hit;
	int					side;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				wall_size;
	double				start;
	double				end;
	t_norm_v2			ray_2;
}						t_norm;

typedef struct s_mlx
{
	void				*connection;
	void				*window;
	t_map				*map;
	t_images			buffer;
	t_movements			movements;
}						t_mlx;

#endif