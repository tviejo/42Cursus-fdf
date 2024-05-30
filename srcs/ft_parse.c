/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:48:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/30 10:56:13 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_lenz(t_map *map)
{
        int     i;
        int     j;
	int	min;
	int	max;

	min = 0;
	max = 0;
        i = 0;
        while (map->map[i] != NULL)
        {
                j = 0;
                while (map->map[i][j] != NULL)
                {
			if (atoi(map->map[i][j]) > max)
				max = atoi(map->map[i][j]);
			else if (atoi(map->map[i][j]) < min)
				min = atoi(map->map[i][j]);
                        j++;
                }
               i++;
        }
	return (max - min);	
}

char	**ft_read_line(int fd)
{
	char	*line;
	char	**point;

	line = get_next_line(fd);
	point = ft_split( line, ' ');
	free(line);
	return (point);
}

int	ft_size_tab(char *argv)
{
	int	fd;
	int	i;
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

static int	ft_leny(char ** map)
{
	int	i;
	
	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

t_map	create_map(char *argv)
{
	int	fd;
	int	nb_line;
	t_map	map;
	int	i;
	int	leny;

	nb_line = ft_size_tab(argv);
	map.map = (char ***)malloc((nb_line + 1) * sizeof(char **));
	if (map.map == NULL)
		return (map);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < nb_line - 1)
	{
        	map.map[i] = ft_read_line(fd);
		if (i > 0 && ft_leny(map.map[i]) != leny)
			return (map.x = 0, map.y = 0, map);
		leny = ft_leny(map.map[i]);
		i++;
	}
	map.map[i] = NULL;
	map.x = i;
	map.y = leny;
	map.z = ft_lenz(&map);
	close(fd);
	return (map);
}
