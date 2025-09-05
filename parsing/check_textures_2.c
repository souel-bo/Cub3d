/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:58:49 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/05 09:11:44 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	validate_texture_format(char **arr)
{
	if (ft_count_argc(arr) != 2)
		return (1);
	if (strcmp(arr[0], "NO") && strcmp(arr[0], "SO") && strcmp(arr[0], "WE")
		&& strcmp(arr[0], "EA"))
		return (1);
	return (0);
}

static int	validate_texture_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

static void	assign_texture_path(char *direction, char *path,
		t_textures *textures, t_map *units)
{
	if (!strcmp(direction, "NO"))
	{
		textures->north_path = ft_strdup(path);
		units->n_count++;
	}
	else if (!strcmp(direction, "SO"))
	{
		textures->south_path = ft_strdup(path);
		units->s_count++;
	}
	else if (!strcmp(direction, "EA"))
	{
		textures->east_path = ft_strdup(path);
		units->e_count++;
	}
	else if (!strcmp(direction, "WE"))
	{
		textures->west_path = ft_strdup(path);
		units->w_count++;
	}
}

int	is_valid_texture(char *str, t_textures *textures, t_map *units)
{
	char	**arr;

	arr = ft_split(str, ' ');
	if (validate_texture_format(arr))
		return (1);
	arr[1] = remove_newline(arr[1]);
	if (validate_texture_file(arr[1]))
		return (1);
	assign_texture_path(arr[0], arr[1], textures, units);
	return (0);
}
