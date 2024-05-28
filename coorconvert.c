/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coorconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:02:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/28 10:08:03 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2dcoor        convertortho(int x, int y, int z, int angle, int zoom)
{
	t_2dcoor	point2D;
	int	xtemp;
	int	ytemp;

	xtemp = x;
	ytemp = y;
	point2D.x = -( (xtemp - ytemp) * cos(1/sqrt(2)) ) * zoom;
	point2D.y = -z * 2 + (( (xtemp + ytemp) * sin(1/sqrt(2)) ) * zoom);
	point2D = ft_rotax(point2D, angle);
	return (point2D);
}

t_2dcoor        ft_rotax(t_2dcoor point2D, int angle)
{
        double rad;
        int     xtemp;

        xtemp = point2D.x;
        rad = angle * (M_PI / 180.0);
        point2D.x = ( xtemp * cos(rad) - point2D.y * sin(rad) );
        point2D.y = ( xtemp * sin(rad) + point2D.y * cos(rad) );

        return (point2D);
}
