/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coorconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:02:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/05 16:07:36 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_3dcoor	ft_zoom(t_3dcoor point3d, t_data *data)
{
	point3d.x *= data->inter.zoom;
	point3d.y *= data->inter.zoom;
	point3d.z *= data->inter.zoom;
	return (point3d);
}

static t_3dcoor	ft_trans(t_3dcoor point3d, t_data *data)
{
	point3d.x += data->inter.transx;
	point3d.y += data->inter.transy;
	point3d.z += data->inter.transz;
	return (point3d);
}

t_2dcoor	convertortho(int x, int y, int z, t_data *data)
{
	t_2dcoor	point2d;
	t_3dcoor	point3d;
	int			xtemp;
	int			ytemp;

	point3d.x = x;
	point3d.y = y;
	point3d.z = z;
	point3d = ft_zoom(point3d, data);
	point3d = ft_rotax(point3d, data);
	point3d = ft_rotay(point3d, data);
	point3d = ft_rotaz(point3d, data);
	point3d = ft_trans(point3d, data);
	xtemp = point3d.x;
	ytemp = point3d.y;
	point2d.x = -((xtemp - ytemp) * 0.76024);
	point2d.y = (-point3d.z / 10 + ((xtemp + ytemp) * 0.64964));
	return (point2d);
}
