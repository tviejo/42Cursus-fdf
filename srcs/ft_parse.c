/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:48:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 12:41:21 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_find_zmaxmin(t_map *map, int i, int j)
{
	map->zmax = 0;
	map->zmin = 0;
	j--;
	i--;
	while (i > 0)
	{
		while (j > 0)
		{
			if (map->map[i][j][0] > map->zmax)
				map->zmax = map->map[i][j][0];
			else if (map->map[i][j][0] < map->zmin)
				map->zmin = map->map[i][j][0];
			j--;
		}
		i--;
	}
}

int	**ft_read_line(int fd, int *leny)
{
	char	*line;
	int		**point;

	line = get_next_line(fd);
	*leny = ft_count_words(line, ' ');
	point = ft_split_map(line, ' ', *leny);
	free(line);
	return (point);
}

int	ft_size_tab(char *argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	i = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line != NULL)
		free(line);
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
			return (map.x = 0, map.y = 0, map);
		map.y = leny;
		i++;
	}
	map.map[i] = NULL;
	map.x = i;
	map.y = leny;
	ft_find_zmaxmin(&map, map.x, map.y);
	return (close(fd), map);
}
