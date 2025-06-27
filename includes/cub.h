/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 04:01:12 by souel-bo          #+#    #+#             */
/*   Updated: 2025/06/27 00:12:52 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>
#include "../get_next_line/get_next_line.h"
#include "libft.h"


typedef struct s_textures
{
    char *north_path;
    char *west_path;
    char *east_path;
    char *south_path;
} t_textures;

typedef struct s_map
{
    char **map;
    int direction;
    int flor_collor;
    int sky_collor;
    t_textures *textures;
} t_map;

#endif