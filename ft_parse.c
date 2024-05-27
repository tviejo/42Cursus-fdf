/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:48:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/26 18:09:15 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_read_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	return (ft_split( line, ' '));
}

int	ft_size_tab(char *argv)
{
	int	fd;
	int	i;

	fd = open(argv, O_RDONLY);
	i = 1;
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

t_map	create_map(char *argv)
{
	int	fd;
	int	nb_line;
	t_map	map;
	int	i;

	nb_line = ft_size_tab(argv);
	map.map = (char ***)malloc((nb_line + 1) * sizeof(char **));
	if (map.map == NULL)
		return (map);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < nb_line - 1)
	{
        	map.map[i] = ft_read_line(fd);
		i++;
	}
	map.map[i] = NULL;
	map.x = i;
	map.y = i;
	close(fd);
	return (map);
}
