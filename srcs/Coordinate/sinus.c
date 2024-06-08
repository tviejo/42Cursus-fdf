/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:45:55 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/08 09:45:57 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_sinus(int i, int j, t_data *data)
{
	if (data->phase != 0)
		return (data->map.map[i][j][0] * sin(((j * 10) + data->phase) / 10));
	else
		return (data->map.map[i][j][0]);
}
