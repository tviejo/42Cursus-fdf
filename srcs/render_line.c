/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:35:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 15:18:29 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham(t_line line, double *deltax, double *deltay, int *pixels)
{
	*deltax = line.end.x - line.begin.x;
	*deltay = line.end.y - line.begin.y;
	*pixels = sqrt((*deltax * *deltax) + (*deltay * *deltay));
	*deltax /= *pixels;
	*deltay /= *pixels;
}
/*
int	render_line(t_img *img, t_line line)
{
	double	deltax;
	double	deltay;
	int		pixels;
	int		color;

	//ft_bresenham(line, &deltax, &deltay, &pixels);
    deltax = line.end.x - line.begin.x;
	deltay = line.end.y - line.begin.y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	color = ft_color_line(line, pixels);
	while (pixels)
	{
		if (ft_pixel_is_printable(line.begin.x, line.begin.y) == true)
		{
			if (line.begin.z < line.end.z)
				img_pix_put(img, line.begin.x, line.begin.y,
					ft_ncolor_change(line.end.color, pixels * color, 2));
			else
				img_pix_put(img, line.begin.x, line.begin.y,
					ft_ncolor_change(line.end.color, pixels * color, 1));
		}
		line.begin.x += deltax;
		line.begin.y += deltay;
		--pixels;
	}
	return (0);
}
*/

int	render_line(t_img *img, t_line line)
{
	double	deltax;
	double	deltaY;
	int		pixels;
	double	pixelx;
	double	pixely;
	float	color_change;

    ft_bresenham(line, &deltax, &deltaY, &pixels);
	pixelx = line.begin.x;
	pixely = line.begin.y;
	color_change = ft_color_line(line, pixels);
	while (pixels)
	{
		if (ft_pixel_is_printable(pixelx, pixely) == true)
		{
			if (line.begin.z < line.end.z)
				img_pix_put(img, pixelx, pixely,
					ft_ncolor_change(line.end.color, pixels
						* color_change, 2));
			else
				img_pix_put(img, pixelx, pixely,
					ft_ncolor_change(line.end.color, pixels
						* color_change, 1));
		}
		pixelx += deltax;
		pixely += deltaY;
		--pixels;
	}
	return (0);
}

bool	ft_line_is_printable(t_2dcoor end, t_2dcoor begin)
{
	if (end.x > WINDOW_WIDTH && end.y > WINDOW_HEIGHT && begin.x > WINDOW_WIDTH
		&& begin.y > WINDOW_HEIGHT)
		return (false);
	if (end.x < 0 && end.y < 0 && begin.x < 0 && begin.y < 0)
		return (false);
	if (end.x > WINDOW_WIDTH && end.y < 0 && begin.x > WINDOW_WIDTH
		&& begin.y < 0)
		return (false);
	if (end.x < 0 && end.y > WINDOW_HEIGHT && begin.x < 0
		&& begin.y > WINDOW_HEIGHT)
		return (false);
	return (true);
}

void	ft_create_line(int i, int j, t_data *data, int mode)
{
	t_2dcoor	end;
	t_2dcoor	begin;

	if (mode == 1)
	{
		begin = convertortho(i, j, data->map.map[i][j][0], data);
		end = convertortho(i + 1, j, data->map.map[i + 1][j][0], data);
		begin.color = ft_parse_color(*data, data->map.map[i][j]);
		end.color = ft_parse_color(*data, data->map.map[i + 1][j]);
		begin.z = data->map.map[i][j][0];
		end.z = data->map.map[i + 1][j][0];
		//if (ft_line_is_printable(end, begin) == true)
			render_line(&data->img, (t_line){begin, end, data->inter.colorl});
	}
	else
	{
		begin = convertortho(i, j, data->map.map[i][j][0], data);
		end = convertortho(i, j + 1, data->map.map[i][j + 1][0], data);
		begin.color = ft_parse_color(*data, data->map.map[i][j]);
		end.color = ft_parse_color(*data, data->map.map[i][j + 1]);
		begin.z = data->map.map[i][j][0];
		end.z = data->map.map[i][j + 1][0];
		//if (ft_line_is_printable(end, begin) == true)
			render_line(&data->img, (t_line){begin, end, data->inter.colorl});
	}
}

void	ft_put_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.x - 1)
	{
		j = 0;
		while (j < data->map.y)
		{
			ft_create_line(i, j, data, 1);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < data->map.y - 1)
	{
		i = 0;
		while (i < data->map.x)
		{
			ft_create_line(i, j, data, 2);
			i++;
		}
		j++;
	}
}
