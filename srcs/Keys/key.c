/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/11 10:30:07 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_key_deform(int keysym, t_data *data)
{
	if (keysym == XK_Up)
		data->inter.zoom += 1;
	if (keysym == XK_Down)
		if (data->inter.zoom > 1)
			data->inter.zoom -= 1;
	if (keysym == XK_t)
		if (data->inter.deformx < 100)
			data->inter.deformx *= 2;
	if (keysym == XK_y)
		if (data->inter.deformx > 1)
			data->inter.deformx /= 2;
	if (keysym == XK_g)
		if (data->inter.deformy < 100)
			data->inter.deformy *= 2;
	if (keysym == XK_h)
		if (data->inter.deformy > 1)
			data->inter.deformy /= 2;
	if (keysym == XK_b)
		if (data->inter.deformz < 100)
			data->inter.deformz *= 2;
	if (keysym == XK_n)
		if (data->inter.deformz > 0.1)
			data->inter.deformz /= 2;
}

static void	ft_key_movement(int keysym, t_data *data)
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
	if (keysym == XK_u || keysym == XK_i || keysym == XK_j || keysym == XK_k
		|| keysym == XK_o || keysym == XK_p)
		data->bchange = 1;
	if (keysym == XK_u)
		data->inter.colorb = ft_ncolor_change(data->inter.colorb, 10, 2);
	if (keysym == XK_i)
		data->inter.colorl = ft_ncolor_change(data->inter.colorl, 10, 1);
	if (keysym == XK_j)
		if (data->inter.gradientspeed < 50)
			data->inter.gradientspeed += 1;
	if (keysym == XK_k)
		if (data->inter.gradientspeed > 0)
			data->inter.gradientspeed -= 1;
	if (keysym == XK_o)
		if (data->inter.gradientsize < 10)
			data->inter.gradientsize *= 2;
	if (keysym == XK_p)
		if (data->inter.gradientsize > 0.1)
			data->inter.gradientsize /= 2;
}

int	handle_keypress(int keysym, t_data *data)
{
	data->action = 1;
	ft_put_hud(data);
	ft_key_pages(keysym, data);
	if (keysym == XK_F1)
		ft_init_view(data, data->map);
	if (keysym == XK_8)
		data->inter.map_mode = 1;
	if (keysym == XK_7)
		data->inter.map_mode = 0;
	ft_key_view(keysym, data);
	ft_key_movement(keysym, data);
	ft_key_deform(keysym, data);
	ft_key_color(keysym, data);
	ft_key_party(keysym, data);
	return (0);
}
