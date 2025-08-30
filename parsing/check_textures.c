/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:01:46 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/30 18:08:51 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*remove_newline(char *str)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	len = ft_strlen(str);
	new_line = malloc(sizeof(char) * (len + 1));
	while (i < len - 1)
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\0';
	free(str);
	return (new_line);
}

int	is_valid_texture(char *str, t_textures *textures, t_map *units)
{
	int		i;
	char	**arr;
	int		fd;

	i = 0;
	arr = ft_split(str, ' ');
	if (ft_count_argc(arr) != 2)
		return (free_arr(arr), printf("ff\n"), 1);
	if (strcmp(arr[0], "NO") && strcmp(arr[0], "SO") && strcmp(arr[0], "WE")
		&& strcmp(arr[0], "EA"))
		return (free_arr(arr), printf("bb\n"), 1);
	arr[1] = remove_newline(arr[1]);
	fd = open(arr[1], O_RDONLY);
	if (fd < 0)
		return (free_arr(arr), printf("nn\n"), 1);
	if (!strcmp(arr[0], "NO"))
	{
		textures->north_path = ft_strdup(arr[1]);
		units->n_count++;
	}
	else if (!strcmp(arr[0], "SO"))
	{
		textures->south_path = ft_strdup(arr[1]);
		units->s_count++;
	}
	else if (!strcmp(arr[0], "EA"))
	{
		textures->east_path = ft_strdup(arr[1]);
		units->e_count++;
	}
	else if (!strcmp(arr[0], "WE"))
	{
		textures->west_path = ft_strdup(arr[1]);
		units->w_count++;
	}
	return (free_arr(arr), close(fd), 0);
}

int	check_req_textures(t_textures *textures, t_map *units)
{
	if (!textures->north_path || !textures->south_path || !textures->east_path
		|| !textures->west_path)
		return (1);
	if (units->e_count != 1 || units->s_count != 1 || units->w_count != 1
		|| units->n_count != 1)
		return (1);
	return (0);
}

int	check_textures(char **textures, t_map *units)
{
	int			i;
	t_textures	*v_textures;

	v_textures = malloc(sizeof(t_textures));
	units->e_count = 0;
	units->s_count = 0;
	units->w_count = 0;
	units->n_count = 0;
	i = 0;
	while (textures[i])
	{
		if (is_valid_texture(textures[i], v_textures, units))
			return (1);
		i++;
	}
	if (check_req_textures(v_textures, units))
		return (1);
	units->textures = v_textures;
	return (0);
}
