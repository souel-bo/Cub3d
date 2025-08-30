/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:01:27 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/30 19:06:28 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_col_valid(t_map *units)
{
	if (!units->floor_collors || !units->ceilling_collors)
		return (1);
	if (units->count_floor != 1 || units->count_ceil != 1)
		return (1);
	if (units->ceilling_collors->blue == -1
		|| units->ceilling_collors->red == -1
		|| units->ceilling_collors->green == -1)
		return (1);
	if (units->floor_collors->blue == -1 || units->floor_collors->red == -1
		|| units->floor_collors->green == -1)
		return (1);
	return (0);
}

int	ft_colors(char **colors, t_map *units)
{
	int	i;

	units->count_ceil = 0;
	units->count_floor = 0;
	i = 0;
	while (colors[i])
	{
		if (check_colors(colors[i], units))
			return (1);
		i++;
	}
	if (check_col_valid(units))
		return (1);
	return (0);
}
