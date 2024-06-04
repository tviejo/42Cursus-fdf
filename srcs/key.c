/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 13:22:27 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_free_map(&data->map);
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		data->win_ptr = NULL;
		free(data->mlx_ptr);
		exit(0);
	}
	if (keysym == 122)
		data->inter.zoom += 1;
	if (keysym == 120)
		if (data->inter.zoom > 1)
			data->inter.zoom -= 1;
	if (keysym == 113)
		data->inter.transx += 1;
	if (keysym == 119)
		data->inter.transx -= 1;
	if (keysym == 97)
		data->inter.transy += 1;
	if (keysym == 115)
		data->inter.transy -= 1;
	if (keysym == 101)
		data->inter.rotax += 1;
	if (keysym == 114)
		data->inter.rotax -= 1;
	if (keysym == 100)
		data->inter.rotay += 1;
	if (keysym == 102)
		data->inter.rotay -= 1;
	if (keysym == 99)
		data->inter.rotaz += 1;
	if (keysym == 118)
		data->inter.rotaz -= 1;
	if (keysym == 116)
		data->inter.colorb = ft_ncolor_change(data->inter.colorb, 10,
				2);
	if (keysym == 121)
		data->inter.colorl = ft_ncolor_change(data->inter.colorl, 10,
				1);
	if (keysym == 117)
		if (data->inter.gradientspeed < 50)
			data->inter.gradientspeed += 1;
	if (keysym == 105)
		if (data->inter.gradientspeed > 0)
			data->inter.gradientspeed -= 1;
	if (keysym == 107)
		if (data->inter.gradientsize < 10)
			data->inter.gradientsize *= 2;
	if (keysym == 108)
		if (data->inter.gradientsize > 0.1)
			data->inter.gradientsize /= 2;
	if (keysym == 112)
	{
		if (data->inter.partymode == 1)
		{
			data->inter.partymode = 0;
			data->inter.gradientspeed = 1;
		}
		else
		{
			data->inter.partymode = 1;
			data->inter.gradientspeed = 20;
		}
	}
	return (0);
}
