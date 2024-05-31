/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:42:03 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/31 17:17:33 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_zoom(t_map *map)
{
	if (map->x > map->y)
		return ((WINDOW_WIDTH / map->x) * 0.8);
	else
		return ((WINDOW_HEIGHT / map->y) * 0.8);
}

void	ft_init_view(t_data *data, t_map map)
{
	data->zoom = ft_zoom(&map);
	data->transx = WINDOW_WIDTH / 3;
	data->transy = WINDOW_HEIGHT / 6;
	data->rotax = 0;
	data->rotay = 0;
	data->rotaz = 0;
	data->lenx = map.x;
	data->leny = map.y;
	data->lenz = map.z;
	data->colorb = BLACK_PIXEL;
	data->colorl = BLACK_PIXEL;
	data->partymode = 0;
	data->gradientspeed = 1;
	data->gradientsize = 10;
}
