/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:09:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/29 20:58:09 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    img_pix_put(t_img *img, int x, int y, int color)
{
        char    *pixel;
        int             i;

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

bool    ft_pixel_is_printable(int pixelX , int pixelY)
{
        if (pixelX < 0 || pixelY < 0)
                return (false);
        if (pixelX > WINDOW_WIDTH)
                return (false);
        if (pixelY > WINDOW_WIDTH)
                return (false);
        return (true);
}

int render_line(t_img *img, t_line line)
{
        double deltaX = line.x2 - line.x1;
        double deltaY = line.y2 - line.y1;
        int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
        deltaX /= pixels;
        deltaY /= pixels;
        double pixelX = line.x1;
        double pixelY = line.y1;
        while (pixels)
        {
		if (ft_pixel_is_printable(pixelX, pixelY) == true)
			img_pix_put(img, pixelX, pixelY, line.color);
                pixelX += deltaX;
                pixelY += deltaY;
                --pixels;
        }
        return (0);
}

void    render_background(t_img *img, int color)
{
        int     i;
        int     j;

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

void	ft_create_line(int i, int j, t_map map, t_data *data, int mode)
{
	t_2dcoor        end;
        t_2dcoor        begin;

	if (mode == 1)
	{
		begin = convertortho(i, j, atoi(map.map[i][j]), data);
		end = convertortho(i + 1, j, atoi(map.map[i + 1][j]), data);
		render_line(&data->img, (t_line){ begin.x, begin.y, end.x, end.y, data->colorl});
	}
	else
	{
		begin = convertortho(i, j, atoi(map.map[i][j]), data);
		end = convertortho(i, j + 1, atoi(map.map[i][j + 1]), data);
		render_line(&data->img, (t_line){begin.x, begin.y, end.x, end.y, data->colorl});	
	}
}

int     render(t_data *data)
{
        t_map           map;
        int     i;
        int     j;
	
        render_background(&data->img, data->colorb);
        map = data->map;
        i = 0;
        while (i < map.x - 1)
        {
                j = 0;
                while (j < map.y)
                {
			ft_create_line(i, j, map, data, 1);
                        j++;
                }
        i++;
        }
        j = 0;
        while (j < map.y - 1)
        {
                i = 0;
                while (i < map.x)
                {
			ft_create_line(i ,j, map, data, 2); 
                        i++;
                }
        j++;
        }
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

        return (0);
}

