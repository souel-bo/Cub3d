#include "../includes/cub.h"

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\n')
		return (2);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' &&
			str[i] != '\n' && str[i] != 'N' && str[i] != 'S' &&
			str[i] != 'E' && str[i] != 'W' && str[i] != 'D')
			return (0);
		i++;
	}
	return (1);
}

int	count_lines(char **argv)
{
	int		count;
	int		fd;
	char	*line;
	int		in_map;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	in_map = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line) == 1)
		{
			in_map = 1;
			count++;
		}
		else if (in_map && !is_map_line(line))
			return (free(line), close(fd), -1);
		free(line);
	}
	close(fd);
	return (count);
}

int check_map(t_map *units, char **argv)
{
	char	*line;

	int(in_map), (count), (i), (fd);
	if ((count = count_lines(argv)) == -1)
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	i = 0;
	in_map = 0;
	units->map = malloc(sizeof(char *) * (count + 1));
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line) == 1)
		{
			units->map[i] = ft_strdup(line);
			i++;
			in_map = 1;
		}
		else if (in_map && !is_map_line(line))
			break ;
		free(line);
	}
	units->map[i] = NULL;
	return (close(fd), 0);
}




int	start_parsing(t_map *units, char **argv)
{
	if(check_map(units , argv) == -1)
		return -1;
	if(make_map_cube(units))
		return -1;
	return 0;
}
