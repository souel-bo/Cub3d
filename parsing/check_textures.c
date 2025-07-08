#include "../includes/cub.h"

int	is_valid_texture(char *str, t_textures *textures)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(str, ' ');
	if (ft_count_argc(arr) != 2)
		return (printf("ff\n"),1);
	if (strcmp(arr[0], "NO") && strcmp(arr[0], "SO") && strcmp(arr[0], "WE")
		&& strcmp(arr[0], "EA"))
		return (printf("bb\n"),1);
    printf("%s\n", arr[1]);
    int fd = open(arr[1], O_RDONLY);
	if (fd < 0)
		return (printf("nn\n") , close(fd),1);
	if (!strcmp(arr[0], "NO") && !textures->north_path)
		textures->north_path = arr[1];
	else if (!strcmp(arr[0], "SO") && !textures->south_path)
		textures->south_path = arr[1];
	else if (!strcmp(arr[0], "EA") && !textures->east_path)
		textures->east_path = arr[1];
	else if (!strcmp(arr[0], "WE") && !textures->west_path)
		textures->west_path = arr[1];
	return (close(fd) ,0);
}

int	check_req_textures(t_textures *textures)
{
	if (!textures->north_path || !textures->south_path || !textures->east_path
		|| !textures->west_path)
	{
		return (1);
	}

	return (0);
}

int	check_textures(char **textures, t_map *units)
{
	int			i;
	t_textures	v_textures;

	i = 0;
	while (textures[i])
	{
		if (is_valid_texture(textures[i], &v_textures))
			return (1);
		i++;
	}
    if (check_req_textures(&v_textures))
        return (1);
	
    units->textures = &v_textures;
	return (0);
}
