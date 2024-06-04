/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:36:55 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 12:37:03 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_3dcoor	ft_rotax(t_3dcoor point3D, t_data *data)
{
	double	rad;
	float	ztrans;
	float	ytrans;
	float	zrot;
	float	yrot;

	rad = data->inter.rotax * (0.0174);
	ztrans = point3D.z + (data->inter.lenz / 2);
	ytrans = point3D.y + (data->inter.leny / 2);
	zrot = (ztrans * cos(rad) - ytrans * sin(rad));
	yrot = (ztrans * sin(rad) + ytrans * cos(rad));
	point3D.z = zrot - (data->inter.lenz / 2);
	point3D.y = yrot - (data->inter.leny / 2);
	return (point3D);
}

t_3dcoor	ft_rotaz(t_3dcoor point3D, t_data *data)
{
	double	rad;
	float	xtrans;
	float	ytrans;
	float	xrot;
	float	yrot;

	rad = data->inter.rotaz * (0.0174);
	xtrans = point3D.x + (data->inter.lenx / 2);
	ytrans = point3D.y + (data->inter.leny / 2);
	xrot = (xtrans * cos(rad) - ytrans * sin(rad));
	yrot = (xtrans * sin(rad) + ytrans * cos(rad));
	point3D.x = xrot - (data->inter.lenx / 2);
	point3D.y = yrot - (data->inter.leny / 2);
	return (point3D);
}

t_3dcoor	ft_rotay(t_3dcoor point3D, t_data *data)
{
	double	rad;
	float	xtrans;
	float	ztrans;
	float	xrot;
	float	zrot;

	rad = data->inter.rotay * (0.0174);
	xtrans = point3D.x + (data->inter.lenx / 2);
	ztrans = point3D.z + (data->inter.lenz / 2);
	xrot = (xtrans * cos(rad) - ztrans * sin(rad));
	zrot = (xtrans * sin(rad) + ztrans * cos(rad));
	point3D.x = xrot - (data->inter.lenx / 2);
	point3D.z = zrot - (data->inter.lenz / 2);
	return (point3D);
}
