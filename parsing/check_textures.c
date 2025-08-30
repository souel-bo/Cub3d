/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:01:46 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/30 18:59:47 by yael-yas         ###   ########.fr       */
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
