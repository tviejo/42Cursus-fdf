/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:21:00 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/31 20:15:50 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_color_to_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb <<= 8;
	rgb |= g;
	rgb <<= 8;
	rgb |= b;
	return (rgb);
}

u_int8_t	getred(int rgb)
{
	return (rgb >> 16);
}
u_int8_t	getgreen(int rgb)
{
	return (rgb >> 8);
}

u_int8_t	getblue(int rgb)
{
	return (rgb);
}

int	ft_nb_color_a_to_b(int colorbegin, int colorend)
{
	int	i;

	i = 0;
	while (colorbegin != colorend && i < 1500)
	{
		colorbegin = ft_color_change(colorbegin);
		i++;
	}
	if (i == 1500)
		return (0);
	return (i);
}

int	ft_multiple_color_change(int color, int n, int mode)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (mode == 1)
			color = ft_color_change(color);
		else
			color = ft_color_rchange(color);
		i++;
	}
	return (color);
}

int	ft_color_change(int color)
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;

	r = getred(color);
	g = getgreen(color);
	b = getblue(color);
	if (r < 255 && g == 0 && b == 0)
		r += 1;
	else if (g < 255 && r > 0 && b == 0)
	{
		r -= 1;
		g += 1;
	}
	else if (b < 255 && g > 0 && r == 0)
	{
		g -= 1;
		b += 1;
	}
	else if (b > 0)
	{
		b -= 1;
	}
	else
		return (BLACK_PIXEL);
	return (ft_color_to_rgb(r, g, b));
}

int	ft_color_rchange(int color)
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;

	r = getred(color);
	g = getgreen(color);
	b = getblue(color);
	if (b < 255 && g == 0 && r == 0)
		b += 1;
	else if (g < 255 && b > 0 && r == 0)
	{
		b -= 1;
		g += 1;
	}
	else if (r < 255 && g > 0 && b == 0)
	{
		g -= 1;
		r += 1;
	}
	else if (r > 0)
	{
		r -= 1;
	}
	else
		return (BLACK_PIXEL);
	return (ft_color_to_rgb(r, g, b));
}

/*
	if (color < 16711680)
		color = setRed(color);
	else if (color - 16711680 < 65280)
		color = setGreen(color);
	else if (color - 16711680 - 65280 < 255)
		color = setBlue(color);
	else
		color = BLACK_PIXEL;
	return (color);*/

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
