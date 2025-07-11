/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/11 16:50:13 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

void free_arr(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void free_all_items(t_map *units)
{
	free_arr(units->map);
	free(units->floor_collors);
	free(units->ceilling_collors);
}

int	main(int argc, char **argv)
{
	(void)argc;
	t_map units;
	int i;
	i = 0;
	if (argc != 2 || ft_check_filename(argv[1]) || start_parsing(&units, argv))
		return (printf("map not valid\n"), 0);
	else 
		printf("everything works 100%% \n");
	//while (units.map[i])
	//{
	//	printf("%s", units.map[i]);
	//	i++;
	//}
	free_all_items(&units);
}
