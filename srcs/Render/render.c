/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:09:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/10 18:28:20 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	ft_pixel_is_printable(int pixelX, int pixelY)
{
	if (pixelX < 0 || pixelY < 0)
		return (false);
	if (pixelX >= WINDOW_WIDTH)
		return (false);
	if (pixelY >= WINDOW_WIDTH)
		return (false);
	return (true);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		i = img->bpp - 8;
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

void	render_background(t_img *img, t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			if (data->pixel[i][j] == 1 || data->bchange)
			{
				img_pix_put(img, j, i, color);
			}
			data->pixel[i][j] = 0;
			j++;
		}
		data->nbpixel = 0;
		++i;
	}
}

int	render_fdf(t_data *data)
{
	if (data->parsed_data == 1)
	{
		if (data->inter.partymode == 1)
		{
			data->inter.colorb = ft_ncolor_change(data->inter.colorb,
					data->inter.gradientspeed, 2);
			data->phase++;
		}
		else
			data->phase = 0;
		data->inter.colorl = ft_ncolor_change(data->inter.colorl,
				data->inter.gradientspeed, 1);
		mouse_movement(data);
		render_background(&data->img, data, data->inter.colorb);
		ft_put_line(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
			0, 0);
		ft_put_hud(data);
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->page.exit_page == 1)
	{
		return (render_exit(data));
	}
	else if (data->page.landing_page == 1)
		return (render_landing(data));
	else if (data->page.parsing_page == 1)
		return (render_parsing(data));
	else if (data->parsed_data == 1)
		return (render_fdf(data));
	return (0);
}
