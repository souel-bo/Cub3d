/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:52:46 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/30 18:53:24 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	parse_floor_color(char **colors, t_map *units)
{
	t_flor_collors	*f_color;

	f_color = malloc(sizeof(t_flor_collors));
	if (!f_color)
		return (1);
	f_color->red = ft_atoi_mstr(colors[0]);
	f_color->green = ft_atoi_mstr(colors[1]);
	f_color->blue = ft_atoi_mstr(colors[2]);
	units->count_floor++;
	units->floor_collors = f_color;
	return (0);
}

static int	parse_ceiling_color(char **colors, t_map *units)
{
	t_ceilling_collors	*c_color;

	c_color = malloc(sizeof(t_ceilling_collors));
	if (!c_color)
		return (1);
	c_color->red = ft_atoi_mstr(colors[0]);
	c_color->green = ft_atoi_mstr(colors[1]);
	c_color->blue = ft_atoi_mstr(colors[2]);
	units->count_ceil++;
	units->ceilling_collors = c_color;
	return (0);
}

int	check_colors(char *str, t_map *units)
{
	char	**arr;
	char	**colors;
	int		result;

	arr = ft_split(str, ' ');
	if (ft_count_argc(arr) != 2 || ft_isdigit(arr[1]))
		return (free_arr(arr), 1);
	colors = ft_split(arr[1], ',');
	if (ft_count_argc(colors) != 3)
		return (free_arr(arr), free_arr(colors), 1);
	result = 1;
	if (!strcmp(arr[0], "F"))
		result = parse_floor_color(colors, units);
	else if (!strcmp(arr[0], "C"))
		result = parse_ceiling_color(colors, units);
	return (free_arr(arr), free_arr(colors), result);
}
