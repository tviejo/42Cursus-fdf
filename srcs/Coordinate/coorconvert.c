/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coorconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:02:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/07 18:14:28 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_3dcoor	ft_zoom(t_3dcoor point3d, t_data *data)
{
	point3d.x -= (data->map.x / 2);
	point3d.y -= (data->map.y / 2);
	point3d.z -= (data->map.zmax / 2);
	point3d.x *= data->inter.zoom * data->inter.deformx;
	point3d.y *= data->inter.zoom * data->inter.deformy;
	point3d.z *= data->inter.zoom * data->inter.deformz;
	point3d.x += (data->map.x / 2);
	point3d.y += (data->map.y / 2);
	point3d.z += (data->map.zmax / 2);
	return (point3d);
}

static t_2dcoor	ft_trans(t_2dcoor point2d, t_data *data)
{
	point2d.x += data->inter.transx;
	point2d.y += data->inter.transy;
	return (point2d);
}

t_2dcoor	convert3dto2d(int x, int y, int z, t_data *data)
{
	t_2dcoor	point2d;
	t_3dcoor	point3d;
	float		xtemp;
	float		ytemp;

	point3d.x = x;
	point3d.y = y;
	point3d.z = z;
	point3d = ft_rotax(point3d, data);
	point3d = ft_rotay(point3d, data);
	point3d = ft_rotaz(point3d, data);
	point3d = ft_zoom(point3d, data);
	xtemp = point3d.x;
	ytemp = point3d.y;
	point2d.x = -((xtemp - ytemp) * 0.76024);
	point2d.y = (-point3d.z + ((xtemp + ytemp) * 0.64964));
	point2d = ft_trans(point2d, data);
	return (point2d);
}
