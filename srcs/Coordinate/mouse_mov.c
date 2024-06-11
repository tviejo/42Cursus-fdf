/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:45:42 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/11 10:17:39 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mouse_movement(t_data *data)
{
	int	x;
	int	y;

	if (data->inter.mouser == 1)
	{
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
		data->inter.transx += (x - data->inter.mousex);
		data->inter.transy += (y - data->inter.mousey);
		data->inter.mousex = x;
		data->inter.mousey = y;
	}
	if (data->inter.mousel == 1)
	{
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
		data->inter.rotax -= (x - data->inter.mousex);
		data->inter.rotay -= (y - data->inter.mousey);
		data->inter.mousex = x;
		data->inter.mousey = y;
	}
}
