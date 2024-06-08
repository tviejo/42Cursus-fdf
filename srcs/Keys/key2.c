/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:10:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/08 17:28:26 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_party(int keysym, t_data *data)
{
	if (keysym == XK_l)
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
		data->bchange = 1;
	}
}

void	ft_key_pages(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		if (data->page.exit_page == 0)
			data->page.exit_page = 1;
		else
		{
			ft_close(data);
			exit(SUCCESS);
		}
	}
	if ((keysym == XK_Y || keysym == XK_y) && data->page.exit_page == 1)
	{
		ft_close(data);
		exit(SUCCESS);
	}
	if ((keysym == XK_N || keysym == XK_n) && data->page.exit_page == 1)
		data->page.exit_page = 0;
	if (keysym == XK_space && data->page.landing_page == 1)
	{
		data->page.landing_page = 0;
        data->page.menu_page = 1;
	}
	if ((keysym == XK_y || keysym == XK_Y ) && data->page.menu_page == 1)
	{
        data->page.menu_page = 0;
		data->page.parsing_page = 1;
	}
	if ((keysym == XK_n || keysym == XK_N ) && data->page.menu_page == 1)
	{
		data->file = data->input;
        data->page.menu_page = 0;
		data->page.parsing_page = 1;
	}
}
