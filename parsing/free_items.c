#include "../includes/cub.h"

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
