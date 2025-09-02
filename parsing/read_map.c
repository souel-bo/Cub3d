/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:26:57 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/02 00:59:52 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_is_space(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == ' ' || arr[i][0] == '\t')
			return (1);
		i++;
	}
	return (0);
}

static int	read_and_validate_sections(int fd, t_parse_file *collec)
{
	char	**swp;

	collec->step_one = read_file(fd);
	collec->step_two = read_file(fd);
	collec->step_three = read_file(fd);
	collec->step_four = read_file(fd);
	if (!*collec->step_one || !*collec->step_two || !*collec->step_three)
		return (printf("map not complited\n"), 1);
	if (collec->step_one[0][0] == 'F' || collec->step_one[0][0] == 'C')
	{
		swp = collec->step_one;
		collec->step_one = collec->step_two;
		collec->step_two = swp;
	}
	if (*collec->step_four || ft_is_space(collec->step_four)
		|| ft_is_space(collec->step_two))
		return (printf("param 4\n"), 1);
	return (0);
}

int	start_parsing(t_map *units, char **argv)
{
	int				fd;
	t_parse_file	*collec;

	fd = open(argv[1], O_RDONLY);
	collec = ft_malloc(sizeof(t_parse_file));
	collec->step_one = NULL;
	collec->step_two = NULL;
	collec->step_three = NULL;
	collec->step_four = NULL;
	if (read_and_validate_sections(fd, collec))
		return (close(fd), 1);
	close(fd);
	if (check_textures(collec->step_one, units))
		return (printf("textures\n"), 1);
	if (ft_colors(collec->step_two, units))
		return (printf("colors\n"), 1);
	units->map = collec->step_three;
	collec->step_three = NULL;
	if (make_map_cube(units))
		return (printf("map\n"), -1);
	return (0);
}
