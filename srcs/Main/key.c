/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/06 14:30:55 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_movement(int keysym, t_data *data)
{
	if (keysym == XK_q)
		data->inter.transx += 2;
	if (keysym == XK_w)
		data->inter.transx -= 2;
	if (keysym == XK_a)
		data->inter.transy += 2;
	if (keysym == XK_s)
		data->inter.transy -= 2;
	if (keysym == XK_z)
		data->inter.transz += 10;
	if (keysym == XK_x)
		data->inter.transz -= 10;
	if (keysym == XK_e)
		data->inter.rotax += 2;
	if (keysym == XK_r)
		data->inter.rotax -= 2;
	if (keysym == XK_d)
		data->inter.rotay += 2;
	if (keysym == XK_f)
		data->inter.rotay -= 2;
	if (keysym == XK_c)
		data->inter.rotaz += 2;
	if (keysym == XK_v)
		data->inter.rotaz -= 2;
}

void	ft_key_color(int keysym, t_data *data)
{
	if (keysym == XK_t)
		data->inter.colorb = ft_ncolor_change(data->inter.colorb, 10,
				2);
	if (keysym == XK_y)
		data->inter.colorl = ft_ncolor_change(data->inter.colorl, 10,
				1);
	if (keysym == XK_u)
		if (data->inter.gradientspeed < 50)
			data->inter.gradientspeed += 1;
	if (keysym == XK_i)
		if (data->inter.gradientspeed > 0)
			data->inter.gradientspeed -= 1;
	if (keysym == XK_k)
		if (data->inter.gradientsize < 10)
			data->inter.gradientsize *= 2;
	if (keysym == XK_l)
		if (data->inter.gradientsize > 0.1)
			data->inter.gradientsize /= 2;
}

void	ft_key_party(int keysym, t_data *data)
{
	if (keysym == XK_p)
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
		exit(SUCCESS);
	}
	if (keysym == XK_n)
		ft_init_view(data, data->map);
	if (keysym == XK_Up)
		data->inter.zoom += 1;
	if (keysym == XK_Down)
		data->inter.zoom -= 1;
	if (keysym == XK_m)
	{
		if (data->inter.view == ISOMETRIC)
			data->inter.view = PERSPECTIVE;
		else
			data->inter.view = ISOMETRIC;
	}
	ft_key_movement(keysym, data);
	ft_key_color(keysym, data);
	ft_key_party(keysym, data);
	return (0);
}
