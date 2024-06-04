/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:46:42 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 14:59:56 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hexchartoint(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'A' && c <= 'F')
	{
		return (c - 'A' + 10);
	}
	else if (c >= 'a' && c <= 'f')
	{
		return (c - 'a' + 10);
	}
	else
	{
		return (-1);
	}
}

int	hexstringtoint(const char *hexString)
{
	int	result;
	int	i;
	int	convert;

	result = 0;
	convert = 0;
	i = 0;
	while (hexString[i] != 'x' && hexString[i] != '\0' && hexString[i] != 'X')
		i++;
	i++;
	if (hexString[i] != '\0')
	{
		while (hexString[i] != '\0')
		{
			convert = 1;
			if (hexchartoint(hexString[i]) != -1)
				result = result * 16 + hexchartoint(hexString[i]);
			else
				break ;
			i++;
		}
	}
	if (convert == 1)
		return (result);
	else
		return (-1);
}

unsigned int	ft_parse_color(t_data data, int *zcolor)
{
	if (zcolor[1] >= 0)
	{		
		return (zcolor[1]);
	}
	else if (zcolor[0] > 0)
		return (ft_ncolor_change(data.inter.colorl, zcolor[0]
				* data.inter.gradientsize, 1));
	else
		return (ft_ncolor_change(data.inter.colorl, zcolor[0]
				* data.inter.gradientsize, 2));
	return (BLACK_PIXEL);
}
