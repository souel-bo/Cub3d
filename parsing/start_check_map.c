/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:30:09 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/01 20:50:15 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	biggest_line(char **map)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	tmp = 0;
	while (map[i])
	{
		if ((tmp = ft_strlen(map[i])) > len)
			len = tmp;
		i++;
	}
	return (len);
}

char	*add_underline(char *line, int size)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = malloc(sizeof(char) * (size + 2));
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (i < size)
	{
		while (i < size - 1)
		{
			new_line[i] = ' ';
			i++;
		}
	}
	new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	**duplacate_map(t_map *units, int size)
{
	int		i;
	int		count;
	char	**tmp_map;

	i = 0;
	count = ft_count_argc(units->map);
	tmp_map = malloc(sizeof(char *) * (count + 1));
	while (units->map[i])
	{
		tmp_map[i] = add_underline(units->map[i], size);
		i++;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

int	check_characters(char **tmp_map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == 'W' || tmp_map[i][j] == 'S'
				|| tmp_map[i][j] == 'E' || tmp_map[i][j] == 'N')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	make_map_cube(t_map *units)
{
	int		i;
	int		long_line;
	char	**tmp_map;

	i = 0;
	long_line = biggest_line(units->map);
	tmp_map = duplacate_map(units, long_line);
	if (check_characters(tmp_map))
		return (free_arr(tmp_map),1);
	if (setup_for_flood_fill(tmp_map))
		return (free_arr(tmp_map), 1);
	return (free_arr(tmp_map), 0);
}
