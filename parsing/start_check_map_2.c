/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:32:18 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 00:33:53 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_valid_characters(char **tmp_map)
{
	int	i;
	int	j;

	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] != '0' && tmp_map[i][j] != '1' &&
				tmp_map[i][j] != 'W' && tmp_map[i][j] != 'S' &&
				tmp_map[i][j] != 'E' && tmp_map[i][j] != 'N' &&
				tmp_map[i][j] != 'D' && tmp_map[i][j] != ' ' &&
				tmp_map[i][j] != '\n')
			{
				printf("invalid character\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
