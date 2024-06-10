/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:25:55 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/10 16:25:57 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_convert_positive(t_map *map, int i, int j)
{
	int	jmax;

	jmax = j;
	if (map->zmin < 0)
	{
		j--;
		i--;
		while (i >= 0)
		{
			j = jmax - 1;
			while (j >= 0)
			{
				map->map[i][j][0] = (map->map[i][j][0] - map->zmin);
				j--;
			}
			i--;
		}
		map->zmax = map->zmax + abs(map->zmin);
		map->zmin = 0;
	}
}
