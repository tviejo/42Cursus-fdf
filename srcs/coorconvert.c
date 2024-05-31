/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coorconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:02:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/31 20:20:30 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_2dcoor	ft_trans(t_2dcoor point2D, t_data *data)
{
	point2D.x = point2D.x + data->transx;
	point2D.y = point2D.y + data->transy;
	return (point2D);
}

t_3dcoor	ft_rotax(t_3dcoor point3D, t_data *data)
{
	double	rad;
	float	ztrans;
	float	ytrans;
	float	zrot;
	float	yrot;

	rad = data->rotax * (3.14 / 180.0);
	ztrans = point3D.z - (data->lenz / 2);
	ytrans = point3D.y - (data->leny / 2);
	zrot = (ztrans * cos(rad) - ytrans * sin(rad));
	yrot = (ztrans * sin(rad) + ytrans * cos(rad));
	point3D.z = zrot + (data->lenz / 2);
	point3D.y = yrot + (data->leny / 2);
	return (point3D);
}

t_3dcoor	ft_rotaz(t_3dcoor point3D, t_data *data)
{
	double	rad;
	float	xtrans;
	float	ytrans;
	float	xrot;
	float	yrot;

	rad = data->rotaz * (3.14 / 180.0);
	xtrans = point3D.x - (data->lenx / 2);
	ytrans = point3D.y - (data->leny / 2);
	xrot = (xtrans * cos(rad) - ytrans * sin(rad));
	yrot = (xtrans * sin(rad) + ytrans * cos(rad));
	point3D.x = xrot + (data->lenx / 2);
	point3D.y = yrot + (data->leny / 2);
	return (point3D);
}

t_3dcoor	ft_rotay(t_3dcoor point3D, t_data *data)
{
	double	rad;
	float	xtrans;
	float	ztrans;
	float	xrot;
	float	zrot;

	rad = data->rotay * (3.14 / 180.0);
	xtrans = point3D.x - (data->lenx / 2);
	ztrans = point3D.z - (data->lenz / 2);
	xrot = (xtrans * cos(rad) - ztrans * sin(rad));
	zrot = (xtrans * sin(rad) + ztrans * cos(rad));
	point3D.x = xrot + (data->lenx / 2);
	point3D.z = zrot + (data->lenz / 2);
	return (point3D);
}

t_2dcoor	convertortho(int x, int y, int z, t_data *data, int color)
{
	t_2dcoor	point2D;
	t_3dcoor	point3D;
	int			xtemp;
	int			ytemp;

	point3D.x = x * data->zoom;
	point3D.y = y * data->zoom;
	point3D.z = z * data->zoom;
	point3D = ft_rotax(point3D, data);
	point3D = ft_rotay(point3D, data);
	point3D = ft_rotaz(point3D, data);
	xtemp = point3D.x;
	ytemp = point3D.y;
	point2D.x = -((xtemp - ytemp) * 0.76024);
	point2D.y = (-point3D.z / 10 + ((xtemp + ytemp) * 0.64964));
	point2D = ft_trans(point2D, data);
	point2D.color = color;
	return (point2D);
}
