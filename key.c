/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:17 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/28 15:59:29 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     handle_keypress(int keysym, t_data *data)
{
        if (keysym == XK_Escape)
        {	
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);	
                mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
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
	if (keysym == 101)
                data->rotax += 1;
        if (keysym == 114)
                data->rotax -= 1;
        if (keysym == 100)
                data->rotay += 1;
        if (keysym == 102)
                data->rotay -= 1;
	if (keysym == 67)
                data->rotaz += 1;
        if (keysym == 118)
                data->rotaz -= 1;
	ft_putchar(keysym);
        return (0);
}

