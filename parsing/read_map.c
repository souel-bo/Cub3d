/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:26:57 by yael-yas          #+#    #+#             */
/*   Updated: 2025/07/22 03:17:38 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	**read_file(int fd)
{
	char	*line;
	int		i;
	char	**array;

	i = 0;
	array = malloc(sizeof(char *) * 100);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (*line != '\n')
			break ;
		free(line);
	}
	while (line != NULL)
	{
		if (!*line || *line == '\n')
		{
			free(line);
			break ;
		}
		else
		{
			array[i] = line;
			i++;
		}
		line = get_next_line(fd);
	}
	array[i] = NULL;
	return (array);
}

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
void free_collec(t_parse_file *collec)
{
	if (collec->step_one)
		free_arr(collec->step_one);
	if (collec->step_two)	
		free_arr(collec->step_two);
	if (collec->step_three)
		free_arr(collec->step_three);
	if (collec->step_four)
		free_arr(collec->step_four);
	free(collec);
}

int	start_parsing(t_map *units, char **argv)
{
	int				fd;
	int				i;
	t_parse_file	*collec;
	char **swp;

	(void)units;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	collec = malloc(sizeof(t_parse_file));
	collec->step_one = NULL;
	collec->step_two = NULL;
	collec->step_three = NULL;
	collec->step_four = NULL;
	collec->step_one = read_file(fd);
	collec->step_two = read_file(fd);
	collec->step_three = read_file(fd);
	collec->step_four = read_file(fd);
	if (!*collec->step_one || !*collec->step_two|| !*collec->step_three)
		return(printf("map not complited\n") , free_collec(collec) , close(fd) ,1);
	close(fd);
	if (collec->step_one[0][0] == 'F' || collec->step_one[0][0] == 'C')
	{
		swp = collec->step_one;
		collec->step_one = collec->step_two;
		collec->step_two = swp;
	}
	if (*collec->step_four || ft_is_space(collec->step_four)
		|| ft_is_space(collec->step_two))
		return (free_collec(collec) , printf("param 4\n"), 1);
	if (check_textures(collec->step_one, units))
		return (free_collec(collec) ,printf("textures\n"), 1);
	if (ft_colors(collec->step_two, units))
		return (free_collec(collec) ,printf("colors\n"), 1);
	units->map = collec->step_three;
	collec->step_three = NULL;
	if (make_map_cube(units))
		return (free_collec(collec) ,free_all_items(units),printf("map\n"), -1);
	return (free_collec(collec) ,0);
}
