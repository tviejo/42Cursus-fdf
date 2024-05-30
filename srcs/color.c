/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:21:00 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/30 13:42:12 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	setRed(int color)
{
	return (color + 65536);
}

int	setGreen(int color)
{
	return (color + 256);
}

int	setBlue(int color)
{
	return (color + 1);
}

int	ft_multiple_color_change(int color, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		color = ft_color_change(color);
		i++;
	}
	return (color);
}

int	ft_color_change(int color)
{
	if (color < 16711680)
		color = setRed(color);
	else if (color - 16711680 < 65280)
		color = setGreen(color);
	else if (color - 16711680 - 65280 < 255)
		color = setBlue(color);
	else
		color = BLACK_PIXEL;
	return (color);
}
/*
int	main(void)
{
	int	i;
	int	color;

	color = 0xffffff;
	i = 0;
	while (i < 1000)
	{
		color = ft_color_change(color);
		i++;
	}
}
*/
