/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coorconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:02:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/28 15:53:30 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2dcoor        ft_trans(t_2dcoor point2D, t_data *data)
{
        point2D.x = point2D.x + data->transx;
        point2D.y = point2D.y + data->transy;

        return (point2D);
}

t_2dcoor        ft_rotax(t_2dcoor point2D, t_data *data)
{
        double rad;
        float     xtrans;
	float	ytrans;
	float	xrot;
	float	yrot;

        rad = data->rotax * (M_PI / 180.0);
	xtrans = point2D.x - (data->lenx / 2);
	ytrans = point2D.y - (data->leny / 2);
        xrot = ( xtrans * cos(rad) - ytrans * sin(rad) );
        yrot = ( xtrans * sin(rad) + ytrans * cos(rad) );
	point2D.x = xrot + (data->lenx / 2);
        point2D.y = yrot + (data->leny / 2);

        return (point2D);
}
   
t_2dcoor        convertortho(int x, int y, int z, t_data *data)
{
	t_2dcoor	point2D;
	int	xtemp;
	int	ytemp;

	xtemp = x;
	ytemp = y;
	point2D.x = -((xtemp - ytemp) * cos(1/sqrt(2))) * data->zoom;
	point2D.y = -z * 2 + ((xtemp + ytemp) * sin(1/sqrt(2))) * data->zoom;
	point2D.y = -z * 2 + point2D.y;
	point2D = ft_trans(point2D, data);
	point2D = ft_rotax(point2D, data);
//	point2D = ft_rota(point2D, data->rotay);
//	point2D = ft_rota(point2D, data->rotaz);
	return (point2D);
}
