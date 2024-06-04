/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorconvert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:07:57 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 13:08:00 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_color_to_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb <<= 8;
	rgb |= g;
	rgb <<= 8;
	rgb |= b;
	return (rgb);
}

u_int8_t	getred(int rgb)
{
	return (rgb >> 16);
}

u_int8_t	getgreen(int rgb)
{
	return (rgb >> 8);
}

u_int8_t	getblue(int rgb)
{
	return (rgb);
}
