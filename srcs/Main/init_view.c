/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:42:03 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/07 19:17:48 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_zoom(t_map *map)
{
	if (map->x > map->y)
		return (WINDOW_WIDTH / map->x * 0.9);
	else
		return (WINDOW_HEIGHT / map->y * 0.9);
}

static void	ft_init_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img.pixel = (int **)malloc((1920 + 1) * sizeof(int *));
	while (i < 1920)
	{
		data->img.pixel[i] = (int *)malloc((1920 + 1) * sizeof(int));
		++i;
	}
	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1920)
		{
			data->img.pixel[i][j] = 1;
			j++;
		}
		++i;
	}
}
void	ft_init_view(t_data *data, t_map map)
{
	data->inter.zoom = ft_zoom(&map);
	data->inter.transx = WINDOW_WIDTH / 2;
	data->inter.transy = WINDOW_HEIGHT / 4;
	data->inter.transz = 0;
	data->inter.rotax = 0;
	data->inter.rotay = 0;
	data->inter.rotaz = 0;
	data->inter.mouser = 0;
	data->inter.mousel = 0;
	data->inter.mousex = 0;
	data->inter.mousey = 0;
	data->inter.deformx = 1;
	data->inter.deformy = 1;
	data->inter.deformz = 0.1;
	data->inter.lenx = map.x;
	data->inter.leny = map.y;
	data->inter.lenz = map.zmax - map.zmin;
	data->inter.colorb = 0;
	data->inter.colorl = RED_PIXEL;
	data->inter.partymode = 0;
	data->inter.gradientspeed = 0;
	data->inter.gradientsize = 10;
	data->bchange = 0;
	data->phase = 0;
	data->landing_page = 1;
	data->exit_page = 0;
	data->inter.view = ISOMETRIC;
	ft_init_img(data);
}
