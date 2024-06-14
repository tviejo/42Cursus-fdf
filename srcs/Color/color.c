/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:21:00 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/11 11:01:12 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	render_black(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j, i, BLACK_PIXEL);
			j++;
		}
		++i;
	}
}

int	ft_nb_color_a_to_b(int colorbegin, int colorend)
{
	int	i;

	i = 0;
	while (colorbegin != colorend && i < 10000)
	{
		colorbegin = ft_color_change(colorbegin);
		i++;
	}
	if (i == 10000)
		return (0);
	return (i);
}

int	ft_ncolor_change(int color, int n, int mode)
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

int	ft_color_rchange(int color)
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
		b -= 1;
	else
		return (BLACK_PIXEL);
	return (ft_color_to_rgb(r, g, b));
}

int	ft_color_change(int color)
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
		r -= 1;
	else
		return (BLACK_PIXEL);
	return (ft_color_to_rgb(r, g, b));
}
