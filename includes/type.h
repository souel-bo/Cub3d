/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:29:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 21:41:37 by souel-bo         ###   ########.fr       */
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

typedef struct s_minimap_vars
{
	int					minimap_x;
	int					minimap_y;
	float				player_x;
	float				player_y;
	int					map_rows;
	char				tile;
	float				angle;
	int					line_length;
	int					y;
	int					x;
	float				start_row_f;
	float				end_row_f;
	float				start_col_f;
	float				end_col_f;
	int					start_row;
	int					end_row;
	int					start_col;
	int					end_col;
	int					row;
	int					col;
	int					map_len;
	int					i;
	int					j;
	int					px;
	int					py;
	int					color;
	float				relative_x;
	float				relative_y;
	float				screen_x_f;
	float				screen_y_f;
	int					screen_x;
	int					screen_y;
	float				player_screen_x_f;
	float				player_screen_y_f;
	int					player_screen_x;
	int					player_screen_y;
	int					player_size;
}						t_minimap_vars;

typedef struct s_mlx
{
	void				*connection;
	void				*window;
	t_map				*map;
	t_images			buffer;
	t_movements			movements;
	t_minimap_vars		minimap;
}						t_mlx;

#endif