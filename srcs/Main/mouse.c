/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:46:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/11 11:39:00 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_mouse_press(int keysym, int x, int y, t_data *data)
{
	data->action = 1;
	ft_put_hud(data);
	if (keysym == 4)
		data->inter.zoom += 1;
	if (keysym == 5)
		if (data->inter.zoom > 1)
			data->inter.zoom -= 1;
	if (keysym == 1)
	{
		data->inter.mouser = 1;
		data->inter.mousex = x;
		data->inter.mousey = y;
	}
	if (keysym == 3)
	{
		data->inter.mousel = 1;
		data->inter.mousex = x;
		data->inter.mousey = y;
	}
	return (0);
}

int	handle_mouse_release(int keysym, int x, int y, t_data *data)
{
	x++;
	y++;
	if (keysym == 1)
	{
		data->inter.mouser = 0;
	}
	if (keysym == 3)
	{
		data->inter.mousel = 0;
	}
	return (0);
}
