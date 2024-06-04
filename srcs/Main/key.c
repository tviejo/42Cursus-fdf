/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 16:28:05 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_movement(int keysym, t_data *data)
{
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
}

void	ft_key_color(int keysym, t_data *data)
{
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
}

void	ft_key_party(int keysym, t_data *data)
{
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
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_close(data);
		exit(0);
	}
	if (keysym == 122)
		data->inter.zoom += 1;
	if (keysym == 120)
		if (data->inter.zoom > 1)
			data->inter.zoom -= 1;
	ft_key_movement(keysym, data);
	ft_key_color(keysym, data);
	ft_key_party(keysym, data);
	return (0);
}
