/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:46:36 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/08 16:57:18 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	render_black(t_img *img)
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
/*
int	render_menu(t_data *data)
{
	int		i;
	char	*hud[2];

	hud[0] = "              ";
	if (data->file != NULL)
		hud[0] = "               Map already given       ";
	hud[1] = "             do you want to load another map?    ";
	hud[2] = get_next_line(0);
	hud[3] = "press enter to load a the new map or space to stay whit the old one";
	render_black(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	ft_parsing(data);
	i = 0;
	while (i < 1)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 100,
			WINDOW_HEIGHT / 2 + i * 20 - 20, WHITE_PIXEL, hud[i]);
		i++;
	}
	data->page.parsing_page = 0;
	data->inter.zoom = ft_zoom(&data->map);
	data->inter.lenx = data->map.x;
	data->inter.leny = data->map.y;
	data->inter.lenz = data->map.zmax - data->map.zmin;
	return (0);
}*/

int	render_parsing(t_data *data)
{
	int		i;
	char	*hud[2];

	hud[0] = "       Parsing being processed ...       ";
	render_black(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	ft_parsing(data);
	i = 0;
	while (i < 1)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 100,
			WINDOW_HEIGHT / 2 + i * 20 - 20, WHITE_PIXEL, hud[i]);
		i++;
	}
	data->page.parsing_page = 0;
	data->inter.zoom = ft_zoom(&data->map);
	data->inter.lenx = data->map.x;
	data->inter.leny = data->map.y;
	data->inter.lenz = data->map.zmax - data->map.zmin;
	return (0);
}

int	render_exit(t_data *data)
{
	int		i;
	char	*hud[2];

	hud[0] = "       Do you really want to exit?       ";
	hud[1] = "     PRESS Y TO EXIT OR N TO HAVE FUN    ";
	render_black(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	i = 0;
	while (i < 2)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 100,
			WINDOW_HEIGHT / 2 + i * 20 - 20, WHITE_PIXEL, hud[i]);
		i++;
	}
	return (0);
}

int	render_landing(t_data *data)
{
	int		i;
	char	*hud[2];

	hud[0] = "       FDF of TVIEJO:       ";
	hud[1] = "  PRESS SPACE TO CONTINUE   ";
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	i = 0;
	while (i < 2)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 60,
			WINDOW_HEIGHT / 2 + i * 20 - 20, WHITE_PIXEL, hud[i]);
		i++;
	}
	return (0);
}
