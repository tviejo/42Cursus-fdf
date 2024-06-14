/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:45:55 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/11 11:52:00 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_sinus(int i, int j, t_data *data)
{
	if (data->phase != 0)
		return (data->map.map[i][j][0] * sin(((j * 10) + data->phase) / 10));
	else
		return (data->map.map[i][j][0]);
}
