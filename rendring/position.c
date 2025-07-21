/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:54:46 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/21 08:58:56 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rendering.h"

void	get_angle(t_map *units, char direction)
{
	if (direction == 'N')
		units->angle = M_PI / 2;
	else if (direction == 'E')
		units->angle = 0;
	else if (direction == 'W')
		units->angle = M_PI;
	else if (direction == 'S')
		units->angle = 3 * M_PI / 2;
}

void	get_player_position(t_map *units)
{
	int	i;
	int	j;

	i = 0;
	while (units->map[i])
	{
		j = 0;
		while (units->map[i][j])
		{
			if (units->map[i][j] == 'N' || units->map[i][j] == 'E'
				|| units->map[i][j] == 'W' || units->map[i][j] == 'S')
			{
				units->player_x = (float)j + 0.5;
				units->player_y = (float)i + 0.5;
				get_angle(units, units->map[i][j]);
				units->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

