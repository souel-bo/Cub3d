#include "../includes/cub.h"

int	check_colors(char *str, t_map *units)
{
	t_flor_collors		*f_color;
	t_ceilling_collors	*c_color;
	char				**arr;
	char				**colors;

	arr = ft_split(str, ' ');
	if (ft_count_argc(arr) != 2)
		return (1);
	colors = ft_split(arr[1], ',');
	if (ft_count_argc(colors) != 3)
		return (1);
	if (!strcmp(arr[0], "F"))
	{
		f_color = malloc(sizeof(t_flor_collors));
		f_color->red = ft_atoi_mstr(colors[0]);
		f_color->green = ft_atoi_mstr(colors[1]);
		f_color->blue = ft_atoi_mstr(colors[2]);
		units->count_floor++;
		units->floor_collors = f_color;
	}
	else if (!strcmp(arr[0], "C"))
	{
		c_color = malloc(sizeof(t_ceilling_collors));
		c_color->red = ft_atoi_mstr(colors[0]);
		c_color->green = ft_atoi_mstr(colors[1]);
		c_color->blue = ft_atoi_mstr(colors[2]);
		units->count_ceil++;
		units->ceilling_collors = c_color;
	}
	return (0);
}

int	check_col_valid(t_map *units)
{
	if (!units->floor_collors || !units->ceilling_collors)
		return (1);
	if (units->count_floor != 1 || units->count_ceil != 1)
		return (1);
	if (units->ceilling_collors->blue == -1 || units->ceilling_collors->red ==
		-1 || units->ceilling_collors->green == -1)
		return (1);
	if (units->floor_collors->blue == -1 || units->floor_collors->red == -1
		|| units->floor_collors->green == -1)
		return (1);
	return (0);
}

int	ft_colors(char **colors, t_map *units)
{
	int	i;

	units->count_ceil = 0;
	units->count_floor = 0;
	i = 0;
	while (colors[i])
	{
		if (check_colors(colors[i], units))
			return (1);
		i++;
	}
	if (check_col_valid(units))
		return (1);
	return (0);
}
