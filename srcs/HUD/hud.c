/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:38:00 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/10 18:37:44 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	color_view(t_data *data, int i)
{
	int	color;

	if (i == 3)
	{
		if (data->free == 1)
			return (GREEN_PIXEL);
		else
			return (WHITE_PIXEL);
	}
	else if (data->free == 0 && (data->view == 1) && i == 0)
		color = GREEN_PIXEL;
	else if (data->free == 0 && (data->view == 2) && i == 1)
		color = GREEN_PIXEL;
	else if (data->free == 0 && (data->view >= 3) && i == 2)
		color = GREEN_PIXEL;
	else
		color = WHITE_PIXEL;
	return (color);
}

void	ft_view_hud(t_data *data)
{
	int		i;
	char	*hud[9];

	hud[0] = "| ISOMETRIC |";
	hud[1] = "|    TOP    |";
	hud[2] = "|    SIDE   |";
	hud[3] = "|    FREE   |";
	hud[4] = "----------------------------------------------------------------";
	hud[5] = "----------------------------------------------------------------";
	i = 0;
	while (i < 4)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 614 + (i
				+ 4) * 103, 60, color_view(data, i), hud[i]);
		i++;
	}
	while (i < 6)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 200, 50
			+ (i - 4) * 20, WHITE_PIXEL, hud[i]);
		i++;
	}
}

static void	ft_inter_hud(t_data *data)
{
	int		i;
	char	*hud[14];

	hud[0] = "         3D           ";
	hud[1] = "----------------------";
	hud[2] = "| Q  -< rotax   >+ W |";
	hud[3] = "| A  -< rotay   >+ S |";
	hud[4] = "| Z  -< rotaz   >+ X |";
	hud[5] = "| E  -< transx  >+ R |";
	hud[6] = "| D  -< transy  >+ F |";
	hud[7] = "| X  -< transx  >+ C |";
	hud[8] = "| T  -< deformx >+ Y |";
	hud[9] = "| G  -< deformy >+ H |";
	hud[10] = "| B  -< deformz >+ N |";
	hud[11] = "|DOWN-<   zoom  >+UP |";
	hud[12] = "|LEFT-< view  >+RIGHT|";
	hud[13] = "----------------------";
	i = 0;
	while (i < 14)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 300 + i * 20,
			WHITE_PIXEL, hud[i]);
		i++;
	}
}

static void	ft_color_hud(t_data *data)
{
	int		i;
	char	*hud[13];

	hud[0] = "         COLOR        ";
	hud[1] = "----------------------";
	hud[2] = "| I   < color line    |";
	hud[3] = "| U   < color back    |";
	hud[4] = "| J  -<   speed  >+ K |";
	hud[5] = "| O  -<   size   >+ P |";
	hud[6] = "----------------------";
	hud[7] = "         OTHER        ";
	hud[8] = "----------------------";
	hud[9] = "| I   < PARTY MODE   |";
	hud[10] = "----------------------";
	i = 0;
	while (i < 11)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 300 + (i + 14) * 20,
			WHITE_PIXEL, hud[i]);
		i++;
	}
}

void	ft_put_hud(t_data *data)
{
	char	*hud[2];
	char	*nbpixel;

	nbpixel = ft_itoa(data->nbpixel);
	hud[0] = "nb pixel print:";
	mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH - 200,
		WINDOW_HEIGHT / 2, WHITE_PIXEL, hud[0]);
	mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH - 100,
		WINDOW_HEIGHT / 2, WHITE_PIXEL, nbpixel);
	free(nbpixel);
	ft_color_hud(data);
	ft_view_hud(data);
	ft_inter_hud(data);
}
