/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/28 13:53:21 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     handle_keypress(int keysym, t_data *data)
{
        if (keysym == XK_Escape)
        {	
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);	
                mlx_destroy_window(data->mlx_ptr, data->win_ptr);
                data->win_ptr = NULL;
        }
	if (keysym == 122)
		data->zoom += 1;
	if (keysym == 120)
		if (data->zoom > 1)
                	data->zoom -= 1;
	if (keysym == 113)
                data->transx += 1;
	if (keysym == 119)
                data->transx -= 1;
	if (keysym == 97)
                data->transy += 1;
        if (keysym == 115)
                data->transy -= 1;
	ft_putchar(keysym);
        return (0);
}

