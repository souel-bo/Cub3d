/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:30:21 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/02 01:02:01 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_single_characters_two(char **map, int *pos)
{
	int	i;
	int	j;

	i = pos[0];
	j = pos[1];
	if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || map[i][j + 1] == ' '
		|| map[i][j - 1] == ' ')
	{
		return (1);
	}
	return (0);
}

int	check_single_characters(char **map)
{
	int	*pos;

	int (i), (j);
	i = 0;
	pos = ft_calloc(sizeof(int), 2);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				map[i][j] = 'X';
				pos[0] = i;
				pos[1] = j;
				if (check_single_characters_two(map, pos))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = ft_count_argc(map) - 1;
	while (map[0][j])
	{
		if (map[0][j] == '0' || map[i][j] == '0')
			return (-1);
		j++;
	}
	j = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[i])
	{
		if (map[i][0] == '0' || map[i][j] == '0')
			return (-1);
		i++;
	}
	return (0);
}

int	setup_for_flood_fill(char **tmp_map)
{
	int	*pos;
	int	i;

	pos = find_character(tmp_map);
	if (flood_fill(tmp_map, pos[1], pos[0]))
		return (printf("erorrrrr\n"), 1);
	if (check_walls(tmp_map))
		return (printf("problem in walls\n"), 1);
	if (check_single_characters(tmp_map))
		return (printf("haaa map mt9oba\n"), 1);
	i = 0;
	return (0);
}
