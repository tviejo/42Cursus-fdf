/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:42:03 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/28 15:40:43 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_zoom(t_map *map)
{
	if (map->x > map->y)
		return ((WINDOW_WIDTH / map->x) / 2 - 1);
	else
		return ((WINDOW_HEIGHT / map->y) / 2 - 1);
}

void	ft_init_view(t_data *data, t_map map)
{
	data->zoom = ft_zoom(&map);
        data->transx = WINDOW_WIDTH / 4;
        data->transy = WINDOW_HEIGHT / 4;
        data->rotax = 0;
	data->rotay = 0;
	data->rotaz = 0;
	data->lenx = map.x;
	data->leny = map.y;
}
