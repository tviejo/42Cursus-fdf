/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:35:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/07 18:05:28 by tviejo           ###   ########.fr       */
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

int	render_line(t_img *img, t_line line)
{
	t_render	render;
	int			pixels;
	double		color_change;

	ft_bresenham(line, &render.deltax, &render.deltay, &pixels);
	render.pixelx = line.begin.x;
	render.pixely = line.begin.y;
	color_change = ft_color_line(line, pixels);
	while (pixels--)
	{
		if (ft_pixel_is_printable(render.pixelx, render.pixely) == true)
		{
			if (line.begin.z < line.end.z)
				img_pix_put(img, render.pixelx, render.pixely,
					ft_ncolor_change(line.end.color, pixels * color_change, 2));
			else
				img_pix_put(img, render.pixelx, render.pixely,
					ft_ncolor_change(line.end.color, pixels * color_change, 1));
			img->pixel[(int)render.pixely][(int)render.pixelx] = 1;
		}
		render.pixelx += render.deltax;
		render.pixely += render.deltay;
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
		begin = convert3dto2d(i, j, ft_sinus(i, j, data), data);
		end = convert3dto2d(i + 1, j, ft_sinus(i + 1, j, data), data);
		begin.color = ft_parse_color(*data, data->map.map[i][j]);
		end.color = ft_parse_color(*data, data->map.map[i + 1][j]);
		begin.z = data->map.map[i][j][0];
		end.z = data->map.map[i + 1][j][0];
		if (ft_line_is_printable(end, begin) == true)
			render_line(&data->img, (t_line){begin, end, data->inter.colorl});
	}
	else
	{
		begin = convert3dto2d(i, j, ft_sinus(i, j, data), data);
		end = convert3dto2d(i, j + 1, ft_sinus(i, j + 1, data), data);
		begin.color = ft_parse_color(*data, data->map.map[i][j]);
		end.color = ft_parse_color(*data, data->map.map[i][j + 1]);
		begin.z = data->map.map[i][j][0];
		end.z = data->map.map[i][j + 1][0];
		if (ft_line_is_printable(end, begin) == true)
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
