/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:09:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 14:53:16 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	ft_pixel_is_printable(int pixelX, int pixelY)
{
	if (pixelX < 0 || pixelY < 0)
		return (false);
	if (pixelX > WINDOW_WIDTH)
		return (false);
	if (pixelY > WINDOW_WIDTH)
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

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	render(t_data *data)
{
	if (data->inter.partymode == 1)
		data->inter.colorb = ft_ncolor_change(data->inter.colorb,
				data->inter.gradientspeed, 2);
	data->inter.colorl = ft_ncolor_change(data->inter.colorl,
			data->inter.gradientspeed, 1);
	render_background(&data->img, data->inter.colorb);
	ft_put_line(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}

/*	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100, WHITE_PIXEL, HUD1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 120, WHITE_PIXEL, HUD2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 140, WHITE_PIXEL, HUD3);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 160, WHITE_PIXEL, HUD4);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 180, WHITE_PIXEL, HUD5);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 200, WHITE_PIXEL, HUD6);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 220, WHITE_PIXEL, HUD7);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 240, WHITE_PIXEL, HUD8);*/