#include "../includes/cub.h"

int	biggest_line(t_map *units)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	tmp = 0;
	while (units->map[i])
	{
		if ((tmp = ft_strlen(units->map[i])) > len)
			len = tmp;
		i++;
	}
	return (len);
}

char	*add_underline(char *line, int size)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = malloc(sizeof(char) * (size + 1));
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (i < size)
	{
		while (i < size - 1)
		{
			new_line[i] = ' ';
			i++;
		}
	}
	new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	**duplacate_map(t_map *units, int size)
{
	int		i;
	int		count;
	char	**tmp_map;

	i = 0;
	count = ft_count_argc(units->map);
	tmp_map = malloc(sizeof(char *) * (count + 1));
	while (units->map[i])
	{
		tmp_map[i] = add_underline(units->map[i], size);
		i++;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

void	make_map_cube(t_map *units)
{
	int		i;
	int		long_line;
	char	**tmp_map;

	i = 0;
	long_line = biggest_line(units);
	tmp_map = duplacate_map(units, long_line);
	while (tmp_map[i])
	{
		printf("%s", tmp_map[i]);
		i++;
	}
}
