/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:42:03 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/11 10:11:23 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_init_zoom(t_map *map)
{
	if (map->x > map->y)
		return (WINDOW_WIDTH / map->x * 0.9);
	else
		return (WINDOW_HEIGHT / map->y * 0.9);
}

int	ft_reset_img(t_data *data)
{
	int	i;
	int	j;
	int	size;

	size = WINDOW_WIDTH;
	if (WINDOW_HEIGHT > size)
		size = WINDOW_HEIGHT;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			data->pixel[i][j] = 1;
	}
	return (0);
}

int	ft_init_img(t_data *data)
{
	int	i;
	int	size;

	size = WINDOW_WIDTH;
	if (WINDOW_HEIGHT > size)
		size = WINDOW_HEIGHT;
	if (data->pixel == NULL)
	{
		data->pixel = (int **)malloc((size + 1) * sizeof(int *));
		if (data->pixel == NULL)
			return (ft_close(data));
		i = -1;
		while (++i < size)
		{
			data->pixel[i] = (int *)malloc((size + 1) * sizeof(int));
			if (data->pixel[i] == NULL)
				return (ft_close(data));
		}
	}
	ft_reset_img(data);
	return (0);
}

void	ft_init_button(t_data *data, t_map map)
{
	if (data->parsed_data == 1)
	{
		data->inter.zoom = ft_init_zoom(&map);
		data->inter.lenx = map.x;
		data->inter.leny = map.y;
		data->inter.lenz = map.zmax - map.zmin;
		data->inter.gradientsize = 768 / map.zmax;
	}
	data->inter.transx = WINDOW_WIDTH / 2;
	data->inter.transy = WINDOW_HEIGHT / 2;
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
	data->inter.colorb = 0;
	data->inter.colorl = BLACK_PIXEL;
	data->inter.partymode = 0;
	data->inter.gradientspeed = 0;
}

void	ft_init_view(t_data *data, t_map map)
{
	data->action = 1;
	data->free = 0;
	data->bchange = 0;
	data->phase = 0;
	data->page.exit_page = 0;
	data->page.parsing_page = 0;
	data->inter.map_mode = 0;
	data->nbpixel = 0;
	ft_init_button(data, map);
	ft_init_img(data);
}
