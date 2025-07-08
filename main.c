/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:12:21 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/07 11:51:35 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_map units;
	int i;
	i = 0;
	if (argc != 2 || start_parsing(&units, argv))
		return (printf("map not valid\n"), 0);
	//while (units.map[i])
	//{
	//	printf("%s", units.map[i]);
	//	i++;
	//}
}
