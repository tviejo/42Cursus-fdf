/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coorconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:02:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 12:48:08 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_2dcoor	ft_trans(t_2dcoor point2D, t_data *data)
{
	point2D.x = point2D.x + data->inter.transx;
	point2D.y = point2D.y + data->inter.transy;
	return (point2D);
}

t_2dcoor	convertortho(int x, int y, int z, t_data *data)
{
	t_2dcoor	point2d;
	t_3dcoor	point3d;
	int			xtemp;
	int			ytemp;

	point3d.x = x * data->inter.zoom;
	point3d.y = y * data->inter.zoom;
	point3d.z = z * data->inter.zoom;
	point3d = ft_rotax(point3d, data);
	point3d = ft_rotay(point3d, data);
	point3d = ft_rotaz(point3d, data);
	xtemp = point3d.x;
	ytemp = point3d.y;
	point2d.x = -((xtemp - ytemp) * 0.76024);
	point2d.y = (-point3d.z / 10 + ((xtemp + ytemp) * 0.64964));
	point2d = ft_trans(point2d, data);
	return (point2d);
}
