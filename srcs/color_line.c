/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:52:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 14:53:03 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_color_line(t_line line, int pixels)
{
	float	color_change;
	float	color_change2;

	color_change = 0;
	color_change2 = 0;
	if (pixels > 0)
	{
		color_change = (ft_nb_color_a_to_b(line.end.color, line.begin.color))
			/ pixels;
		color_change2 = (ft_nb_color_a_to_b(line.begin.color, line.end.color))
			/ pixels;
		if (color_change2 <= color_change)
			color_change = color_change2;
	}
	return (color_change);
}
