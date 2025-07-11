/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:30:21 by yael-yas          #+#    #+#             */
/*   Updated: 2025/07/11 23:09:08 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	*find_character(char **tmp_map)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	j = 0;
	nums = malloc(sizeof(int) * 2);
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == 'N' || tmp_map[i][j] == 'W'
				|| tmp_map[i][j] == 'S' || tmp_map[i][j] == 'E')
			{
				nums[0] = i;
				nums[1] = j;
				return (nums);
			}
			j++;
		}
		i++;
	}
	return (nums);
}

int	flood_fill(char **map, int x, int y)
{
	int	width;
	int	height;

	width = biggest_line(map);
	height = ft_count_argc(map);
	if (x < 0 || y < 0 || x >= width || y >= height)
		return (-1);
	if (map[y][x] == ' ')
		return (-1);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	map[y][x] = 'X';
	if (flood_fill(map, x + 1, y) == -1)
		return (-1);
	if (flood_fill(map, x - 1, y) == -1)
		return (-1);
	if (flood_fill(map, x, y + 1) == -1)
		return (-1);
	if (flood_fill(map, x, y - 1) == -1)
		return (-1);
	return (0);
}

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
	pos = calloc(sizeof(int), 2);
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
					return (free (pos),1);
			}
			j++;
		}
		i++;
	}
	return (free(pos), 0);
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
		return (free(pos) ,printf("erorrrrr\n"), 1);
	if (check_walls(tmp_map))
		return (free(pos) ,printf("problem in walls\n"), 1);
	if (check_single_characters(tmp_map))
		return (free(pos) ,printf("haaa map mt9oba\n"), 1);
	i = 0;
	//while (tmp_map[i])
	//{
	//	printf("%s", tmp_map[i]);
	//	i++;
	//}
	return (free(pos) ,0);
}
