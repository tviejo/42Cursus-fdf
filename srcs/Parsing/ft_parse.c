/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:48:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/10 19:40:29 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_find_zmaxmin(t_map *map, int i, int j)
{
	int	jmax;

	jmax = j;
	map->zmax = 0;
	map->zmin = 0;
	j--;
	i--;
	while (i >= 0)
	{
		j = jmax - 1;
		while (j >= 0)
		{
			if (map->map[i][j][0] > map->zmax)
				map->zmax = map->map[i][j][0];
			if (map->map[i][j][0] < map->zmin)
				map->zmin = map->map[i][j][0];
			j--;
		}
		i--;
	}
	ft_convert_positive(map, map->x, map->y);
}

int	**ft_read_line(int fd, int *leny)
{
	char	*line;
	int		**point;

	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_putstr_fd("Invalid parsing\n", 2);
		exit(0);
	}
	*leny = ft_count_words(line, ' ');
	point = ft_split_map(line, ' ', *leny);
	free(line);
	return (point);
}

int	ft_size_tab(char *argv)
{
	int		fd;
	int		i;
	int		toggle;
	char	*line;

	fd = open(argv, O_RDONLY);
	i = 0;
	toggle = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (close(fd), i);
		free(line);
		i++;
		toggle = 1;
	}
	close(fd);
	return (i);
}

t_map	create_map(char *argv)
{
	int		fd;
	int		nb_line;
	t_map	map;
	int		i;
	int		leny;

	nb_line = ft_size_tab(argv);
	map.map = (int ***)malloc((nb_line + 1) * sizeof(int **));
	if (map.map == NULL)
		return (map);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < nb_line - 1)
	{
		map.map[i] = (int **)ft_read_line(fd, &leny);
		if (i > 0 && map.y != leny)
			return (map.map[i + 1] = NULL, map.error = 1, close(fd), map);
		map.y = leny;
		i++;
	}
	map.map[i] = NULL;
	map.x = i;
	map.y = leny;
	ft_find_zmaxmin(&map, map.x, map.y);
	return (map.error = 0, close(fd), map);
}

int	ft_parsing(t_data *data)
{
	t_map	map;

	map = create_map(data->file);
	if (map.error == 1)
		return (ft_putstr_fd("Invalid parsing\n", 2), ft_free_map(&map),
			ft_close(data));
	if (map.zmax > 500)
		ft_convert_to_big(&map, map.x, map.y);
	data->map = map;
	data->parsed_data = 1;
	return (0);
}
