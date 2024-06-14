/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coorconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:02:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/11 11:08:41 by tviejo           ###   ########.fr       */
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

static t_2dcoor	ft_side_view(t_3dcoor point3d, t_data *data)
{
	t_2dcoor	point2d;
	float		xtemp;
	float		ytemp;

	xtemp = point3d.x;
	ytemp = point3d.y;
	if (data->view == 5)
		xtemp = -xtemp;
	if (data->view == 6)
		ytemp = -ytemp;
	if (data->view == 3 || data->view == 5)
	{
		point2d.x = xtemp;
		point2d.y = -point3d.z;
	}
	else
	{
		point2d.x = ytemp;
		point2d.y = -point3d.z;
	}
	return (point2d);
}

static t_2dcoor	ft_view(t_3dcoor point3d, t_data *data)
{
	t_2dcoor	point2d;
	float		xtemp;
	float		ytemp;
	static int	view = 0;

	if (view != data->view)
		ft_init_view(data, data->map);
	view = data->view;
	xtemp = point3d.x;
	ytemp = point3d.y;
	if (data->view == 1)
	{
		point2d.x = -((xtemp - ytemp) * 0.76024);
		point2d.y = (-point3d.z + ((xtemp + ytemp) * 0.64964));
	}
	else if (data->view == 2)
	{
		point2d.x = ytemp;
		point2d.y = xtemp;
	}
	else
		point2d = ft_side_view(point3d, data);
	return (point2d);
}

t_2dcoor	convert3dto2d(int x, int y, int z, t_data *data)
{
	t_2dcoor	point2d;
	t_3dcoor	point3d;

	point3d.x = x;
	point3d.y = y;
	point3d.z = z;
	point3d = ft_rotax(point3d, data);
	point3d = ft_rotay(point3d, data);
	point3d = ft_rotaz(point3d, data);
	point3d = ft_zoom(point3d, data);
	point2d = ft_view(point3d, data);
	point2d = ft_trans(point2d, data);
	return (point2d);
}
