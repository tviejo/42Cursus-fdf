/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:42:03 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/05 16:11:17 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_zoom(t_map *map)
{
	if (map->x > map->y)
		return (WINDOW_WIDTH / map->x * 0.8);
	else
		return (WINDOW_HEIGHT / map->y * 0.8);
}

void	ft_init_view(t_data *data, t_map map)
{
	data->inter.zoom = ft_zoom(&map);
	data->inter.transx = -WINDOW_WIDTH / 3;
	data->inter.transy = WINDOW_WIDTH / 3;
	data->inter.transz = 0;
	data->inter.rotax = 0;
	data->inter.rotay = 0;
	data->inter.rotaz = 0;
	data->inter.lenx = map.x;
	data->inter.leny = map.y;
	data->inter.lenz = map.zmax - map.zmin;
	data->inter.colorb = 0;
	data->inter.colorl = RED_PIXEL;
	data->inter.partymode = 0;
	data->inter.gradientspeed = 0;
	data->inter.gradientsize = 10;
}
